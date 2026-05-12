/**
 * @file Grafo.h
 * @author Bruno Vieira
 * @brief TAD que implementa um grafo utilizando uma lista ou matriz de adjacências, com suporte para grafos direcionados e bipartidos.
 * @version 0.1
 * @date 2025-05-02
 */

 #pragma once

#include "Vector.h"
#include "Matriz.h"
namespace TADS
{

    class Grafo
    {
    private:
        TADS::Vector<TADS::Vector<unsigned>> _listaAdjacencias;
        TADS::Vector<TADS::Vector<unsigned>> _revListaAdjacencias; //otimizada para grafos direcionados, armazena as adjacências inversas (vértices que apontam para o vértice)
        TADS::Matriz<bool> _matrizAdjacencia;
        TADS::Dicionario<bool> _tipovertice; // 0 para vertice do tipo A, 1 para vertice do tipo B (apenas para grafos bipartidos)
        bool _edirecionada = false;
        bool _ebipartida = false;
        bool _ematrizAdjacencia = true;
        unsigned _numVertices;
        unsigned _numArestas;

    public:
        Grafo();
        Grafo(unsigned numVertices = 0,  bool eMatrizAdjacencia = true, bool direcionada =false, bool bipartida = false);
        ~Grafo() = default;

        // Métodos para manipulação de vértices
        void adicionarVertice(bool tipoVertice = 0); // sempre que for adicionar um vertice, verificar se a matriz/lista tem capacidade, se não tiverem, duplicar o tamanho
        void removerVertice(unsigned vertice);
        bool existeVertice(unsigned vertice) const;

        // Métodos para manipulação de Arestas
        void adicionarAresta(unsigned origem, unsigned destino);
        void removerAresta(unsigned origem, unsigned destino);
        bool existeAresta(unsigned origem, unsigned destino) const;

        unsigned grau(unsigned vertice) const;
        unsigned grauEntrada(unsigned vertice) const;
        unsigned grauSaida(unsigned vertice) const;

        unsigned numVertices() const;
        unsigned numArestas() const;
        void mudarRepresentacao(bool matrizAdjacencia);
    };

} // namespace TADS