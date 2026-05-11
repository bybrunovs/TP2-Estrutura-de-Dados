/**
 * @file Grafo.h
 * @author Bruno Vieira
 * @brief TAD que implementa um grafo utilizando uma lista ou matriz de adjacências, com suporte para grafos direcionados e bipartidos.
 * @version 0.1
 * @date 2025-05-02
 */

 #pragma once

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
        Grafo(unsigned numVertices = 0);
        Grafo(bool direcionada =false , bool ponderada = false, bool bipartida = false, unsigned numVertices = 0);
        ~Grafo();

        // Métodos para manipulação de vértices
        void adicionarVertice();
        void removerVertice(unsigned vertice);
        bool existeVertice(unsigned vertice) const;

        // Métodos para manipulação de Arestas
        void adicionarAresta(unsigned origem, unsigned destino);
        void removerAresta(unsigned origem, unsigned destino);
        bool existeAresta(unsigned origem, unsigned destino) const;

        unsigned grau(unsigned vertice) const;
        unsigned numVertices() const;
        unsigned numArestas() const;
        void mudarRepresentacao(bool matrizAdjacencia);
    };

} // namespace TADS