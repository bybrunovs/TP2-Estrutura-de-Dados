/**
 * @file Dicionario.h
 * @author Bruno Vieira
 * @brief TAD que faz o controle de memoria dinamica de um dicionário utilizando um vetor para armazenar os pares chave-valor
 * @version 0.1
 * @date 2025-05-02
 */

#include "Vector.h"

namespace TADS
{
    template <typename T>
    class Dicionario
    {
    private:
        unsigned _capacidade;
        unsigned _tamanho;
        TADS::Vector<T> _valores;

    public:
        Dicionario();
        Dicionario(unsigned capacidade);
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