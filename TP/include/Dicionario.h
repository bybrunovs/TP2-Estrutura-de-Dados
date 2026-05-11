/**
 * @file Dicionario.h
 * @author Bruno Vieira
 * @brief TAD que faz o controle de memoria dinamica de um dicionário utilizando um vetor para armazenar os pares chave-valor
 * @version 0.1
 * @date 2025-05-02
 */

#pragma once

#include "Vector.h"

namespace TADS
{
    template <typename T>
    class Dicionario
    {
    private:
        TADS::Vector<T> _valores;

    public:
        Dicionario();
        Dicionario(unsigned capacidade);
        ~Dicionario();

        void adicionar(const T &valor);
        void remover(const unsigned &chave);
        bool contem(const unsigned &chave) const;
        T &getValor(const unsigned &chave);
        const T &getValor(const unsigned &chave) const;
        void atualizar(const unsigned &chave, const T &novoValor);
        unsigned tamanho() const;
        bool vazio() const;

        T &operator[](const unsigned &chave);
        const T &operator[](const unsigned &chave) const;
    };

} // namespace TADS

#include "../src/Dicionario.tpp"