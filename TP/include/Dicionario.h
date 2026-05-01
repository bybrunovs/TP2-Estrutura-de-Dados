#include "Vector.h"

namespace TADS
{
    template <typename T>
    class Dicionario
    {
    private:
        unsigned _capacidade;
        unsigned _tamanho;
        Tads::Vector<T> _chaves;
        Tads::Vector<T> _valores;
    public:
        Dicionario(/* args */);
        ~Dicionario();

        void adicionar(const T &chave, const T &valor);
        void remover(const T &chave);
        bool contem(const T &chave) const;
        T &getValor(const T &chave);
        const T &getValor(const T &chave) const;
        void atualizar(const T &chave, const T &novoValor);
        unsigned tamanho() const;
        bool vazio() const;
        

        T &operator[](const T &chave);
        const T &operator[](const T &chave) const;
    };

} // namespace TADS

#include "../src/Dicionario.tpp"