#include "No.h"
#include "Vector.h"

namespace TADS
{

    class Grafo
    {
    private:
        TADS::Vector<TADS::Vector<TADS::No>> adj_matrix;
        bool _edirecionada = false;
        bool _eponderada = false;
        bool _ebipartida = false;
        bool _ematrizAdjacencia = false;
        unsigned _numVertices;
        unsigned _numArestas;

    public:
        Grafo();
        Grafo(unsigned numVertices);
        Grafo(unsigned numVertices, bool direcionada, bool ponderada, bool bipartida);
        ~Grafo();

        void adicionarAresta(unsigned origem, unsigned destino);
        void removerAresta(unsigned origem, unsigned destino);
        bool existeAresta(unsigned origem, unsigned destino) const;
        unsigned grau(unsigned vertice) const;
    };

} // namespace TADS