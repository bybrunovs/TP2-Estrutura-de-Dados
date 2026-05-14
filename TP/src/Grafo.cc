#include "Grafo.h"

namespace TADS
{

    Grafo::Grafo() : _edirecionada(false), _ebipartida(false), _ematrizAdjacencia(true), _numVertices(0), _numArestas(0)
    {
    }

    Grafo::Grafo(unsigned numVertices, bool eMatrizAdjacencia, bool direcionada, bool bipartida) : _numVertices(numVertices), _numArestas(0), _ematrizAdjacencia(eMatrizAdjacencia), _edirecionada(direcionada), _ebipartida(bipartida)
    {
        if (eMatrizAdjacencia)
        {
            this->_matrizAdjacencia = TADS::Matriz<bool>(numVertices, false);
        }
        else
        {
            this->_listaAdjacencias = TADS::Vector<TADS::Vector<unsigned>>(numVertices);
            if (direcionada)
            {
                this->_revListaAdjacencias = TADS::Vector<TADS::Vector<unsigned>>(numVertices);
            }
        }
        if (_ebipartida)
        {
            _tipovertice = TADS::Dicionario<bool>(numVertices);
        }
    }

    void Grafo::adicionarVertice(bool tipoVertice)
    {
        if (this->_ematrizAdjacencia)
        {
            if (this->_matrizAdjacencia.getLinhas() <= this->_numVertices)
            {
                if (this->_matrizAdjacencia.getLinhas() == 0)
                {
                    this->_matrizAdjacencia.redimensionar(1, 1, false);
                }

                this->_matrizAdjacencia.redimensionar(this->_matrizAdjacencia.getLinhas() * 2, this->_matrizAdjacencia.getColunas() * 2, false);
            }
        }
        else
        {
            if (this->_listaAdjacencias.tamanho() <= this->_numVertices)
            {
                this->_listaAdjacencias.push_back(TADS::Vector<unsigned>());
                if (this->_edirecionada)
                {
                    this->_revListaAdjacencias.push_back(TADS::Vector<unsigned>());
                }
            }
        }
        this->_tipovertice.adicionar(tipoVertice);
        this->_numVertices++;
    }

    void Grafo::removerVertice(unsigned vertice)
    {
        // não vai ser necessario implementar
    }

    bool Grafo::existeVertice(unsigned vertice) const
    {
        return vertice < this->_numVertices;
    }

    // Métodos para manipulação de Arestas
    void Grafo::adicionarAresta(unsigned origem, unsigned destino)
    {
        if (!existeVertice(origem) || !existeVertice(destino))
        {
            throw std::out_of_range("Vértice de origem ou destino não existe.");
        }

        if (this->_ebipartida)
        {
            if (this->_tipovertice.getValor(origem) == this->_tipovertice.getValor(destino))
            {
                throw std::invalid_argument("Vértices não podem ser do mesmo tipo em um grafo bipartido.");
            }
        }

        if (this->_ematrizAdjacencia)
        {
            this->_matrizAdjacencia.setElemento(origem, destino, true);
            if (!this->_edirecionada)
            {
                this->_matrizAdjacencia.setElemento(destino, origem, true);
            }
        }
        else
        {
            this->_listaAdjacencias.getElemento(origem).push_back(destino);
            if (!this->_edirecionada)
            {
                this->_listaAdjacencias.getElemento(destino).push_back(origem);
            }
            else
            {
                this->_revListaAdjacencias.getElemento(destino).push_back(origem);
            }
        }

        this->_numArestas++;
    }

    void Grafo::removerAresta(unsigned origem, unsigned destino)
    {
        if (!existeVertice(origem) || !existeVertice(destino))
        {
            throw std::out_of_range("Vértice de origem ou destino não existe.");
        }

        if (this->_ematrizAdjacencia)
        {
            this->_matrizAdjacencia.getElemento(origem, destino) = false;
            if (!this->_edirecionada)
            {
                this->_matrizAdjacencia.getElemento(destino, origem) = false;
            }
        }
        else
        {
            for (unsigned i = 0; i < this->_listaAdjacencias.getElemento(origem).tamanho(); i++)
            {
                if (this->_listaAdjacencias.getElemento(origem).getElemento(i) == destino)
                {
                    this->_listaAdjacencias.getElemento(origem).deleteElemento(i);
                }
            }

            if (!this->_edirecionada)
            {
                for (unsigned i = 0; i < this->_listaAdjacencias.getElemento(destino).tamanho(); i++)
                {
                    if (this->_listaAdjacencias.getElemento(destino).getElemento(i) == origem)
                    {
                        this->_listaAdjacencias.getElemento(destino).deleteElemento(i);
                    }
                }
            }
            else
            {
                for (unsigned i = 0; i < this->_revListaAdjacencias.getElemento(destino).tamanho(); i++)
                {
                    if (this->_revListaAdjacencias.getElemento(destino).getElemento(i) == origem)
                    {
                        this->_revListaAdjacencias.getElemento(destino).deleteElemento(i);
                    }
                }
            }
        }

        this->_numArestas--;
    }

    bool Grafo::existeAresta(unsigned origem, unsigned destino)
    {
        if (!existeVertice(origem) || !existeVertice(destino))
        {
            throw std::out_of_range("Vértice de origem ou destino não existe.");
        }

        if (this->_ematrizAdjacencia)
        {
            return this->_matrizAdjacencia.getElemento(origem, destino);
        }
        else
        {
            TADS::Vector<unsigned> &adjacentes = this->_listaAdjacencias.getElemento(origem);
            for (unsigned i = 0; i < adjacentes.tamanho(); i++)
            {
                if (adjacentes.getElemento(i) == destino)
                {
                    return true;
                }
            }
            return false;
        }
    }

    unsigned Grafo::grau(unsigned vertice)
    {
        if (this->_edirecionada)
        {
            return grauEntrada(vertice) + grauSaida(vertice);
        }
        else
        {
            return grauSaida(vertice);
        }
    }

    unsigned Grafo::grauEntrada(unsigned vertice)
    {
        if (!existeVertice(vertice))
        {
            throw std::out_of_range("Vértice não existe.");
        }

        if (this->_ematrizAdjacencia)
        {
            unsigned grauEntrada = 0;
            for (unsigned i = 0; i < this->_numVertices; i++)
            {
                if (this->_matrizAdjacencia.getElemento(i, vertice))
                {
                    grauEntrada++;
                }
            }
            return grauEntrada;
        }
        else
        {
            return this->_revListaAdjacencias.getElemento(vertice).tamanho();
        }
    }
    unsigned Grafo::grauSaida(unsigned vertice)
    {
        if (!existeVertice(vertice))
        {
            throw std::out_of_range("Vértice não existe.");
        }

        if (this->_ematrizAdjacencia)
        {
            unsigned grauSaida = 0;
            for (unsigned i = 0; i < this->_numVertices; i++)
            {
                if (this->_matrizAdjacencia.getElemento(vertice, i))
                {
                    grauSaida++;
                }
            }
            return grauSaida;
        }
        else
        {
            return this->_listaAdjacencias.getElemento(vertice).tamanho();
        }
    }

    unsigned Grafo::numVertices() const
    {
        return this->_numVertices;
    }
    unsigned Grafo::numArestas() const
    {
        return this->_numArestas;
    }
    void Grafo::mudarRepresentacao(bool matrizAdjacencia)
    {
        if (this->_ematrizAdjacencia == matrizAdjacencia)
        {
            return; // Já está na representação desejada
        }

        if (matrizAdjacencia)
        {
            this->_matrizAdjacencia = TADS::Matriz<bool>(this->_numVertices, this->_numVertices);
            for (unsigned i = 0; i < this->_numVertices; i++)
            {
                for (unsigned j = 0; j < this->_numVertices; j++)
                {
                    this->_matrizAdjacencia.setElemento(i, j, this->_listaAdjacencias.getElemento(i).contains(j));
                    if (!this->_edirecionada)
                    {
                        this->_matrizAdjacencia.setElemento(j, i, this->_listaAdjacencias.getElemento(i).contains(j));
                    }
                    else
                    {
                        this->_matrizAdjacencia.setElemento(j, i, this->_revListaAdjacencias.getElemento(j).contains(i));
                    }
                }
            }
        }
        else
        {
            this->_listaAdjacencias = TADS::Vector<TADS::Vector<unsigned>>(this->_numVertices);
            if (this->_edirecionada)
            {
                this->_revListaAdjacencias = TADS::Vector<TADS::Vector<unsigned>>(this->_numVertices);
            }

            for (unsigned i = 0; i < this->_numVertices; i++)
            {
                for (unsigned j = i; j < this->_numVertices; j++)
                {
                    if (this->_matrizAdjacencia.getElemento(i, j))
                    {
                        this->_listaAdjacencias.getElemento(i).push_back(j);
                        if (this->_edirecionada)
                        {
                            this->_revListaAdjacencias.getElemento(j).push_back(i);
                        }
                    }
                }
            }
        }

        this->_ematrizAdjacencia = matrizAdjacencia;
    }
} // namespace TADS
