/**
 * @file Grafo.h
 * @author Bruno Vieira
 * @brief TAD que implementa um grafo utilizando uma lista ou matriz de adjacências, com suporte para grafos direcionados e bipartidos.
 * @version 0.1
 * @date 2025-05-02
 */

#include "No.h"
#include "Vector.h"
#include "Matriz.h"
namespace TADS
{

    class Grafo
    {
    private:
        TADS::Vector<TADS::Vector<unsigned>> _ListaAdjacencias;
        TADS::Matriz<unsigned> _MatrizAdjacencia;
        
        bool _edirecionada = false;
        bool _ebipartida = false;
        bool _ematrizAdjacencia = false;
        unsigned _numVertices;
        unsigned _numArestas;

    public:
        Grafo();
        Grafo(unsigned numVertices);
        Grafo(unsigned numVertices, bool direcionada, bool ponderada, bool bipartida);
        ~Grafo();

        // Métodos para manipulação de vértices
        void adicionarAresta(unsigned origem, unsigned destino);
        void removerAresta(unsigned origem, unsigned destino);
        bool existeAresta(unsigned origem, unsigned destino) const;

        // Métodos para manipulação de vértices caso o grafo for bipartido
        void adicionarAresta(unsigned origem, TipoNo tipo1, unsigned destino, TipoNo tipo2);
        void removerAresta(unsigned origem, TipoNo tipo1, unsigned destino, TipoNo tipo2);
        bool existeAresta(unsigned origem, TipoNo tipo1, unsigned destino, TipoNo tipo2) const;

        unsigned grau(unsigned vertice) const;
        unsigned numVertices() const;
        unsigned numArestas() const;
        void mudarRepresentacao(bool matrizAdjacencia);
    };

} // namespace TADS