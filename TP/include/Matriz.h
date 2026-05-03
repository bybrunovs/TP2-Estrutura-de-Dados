/**
 * @file Matriz.h
 * @author Bruno Vieira
 * @brief TAD que faz o controle de memoria dinamica de uma matriz utilizando um vetor unidimensional para melhora de performance
 * @version 0.1
 * @date 2025-05-02
 */

#include "Vector.h"
#include "Dicionario.h"

#include <stdexcept>
namespace TADS
{
    template <typename T>

    /**
     * @brief Classe de matriz dinâmica simples.
     *
     * Implementa um contêiner que armazena elementos em um buffer
     * alocado dinamicamente e cresce automaticamente quando necessário.
     */

    class Matriz
    {
    private:
        TADS::Vector<T> _dados; // Armazena os dados da matriz em um vetor unidimensional de tamanho linhas * colunas
        unsigned _linhas;
        unsigned _colunas;

    public:
        /**
         * @brief Cria uma matriz vazia sem capacidade inicial.
         */
        Matriz();


                /**
         * @brief Cria uma matriz com capacidade inicial especificada.
         * @param linhas Número de linhas da matriz.
         * @param colunas Número de colunas da matriz.
         * @param valorPadrao Valor a ser atribuído a cada elemento alocado.
         */
        Matriz(unsigned linhas, unsigned colunas,  const T &valorPadrao = T());

        /**
         * @brief Cria uma matriz com capacidade inicial especificada.
         * @param linhasColunas Número de linhas e colunas da matriz.
         * @param valorPadrao Valor a ser atribuído a cada elemento alocado.
         */
        Matriz(unsigned linhasColunas,  const T &valorPadrao = T());

        ~Matriz() = default;

        /**
         * @brief Substitui o valor de um elemento existente.
         * @param linha Linha do elemento.
         * @param coluna Coluna do elemento.
         * @param valor Novo valor.
         * @throws std::out_of_range se o índice estiver fora dos limites.
         */
        void setElemento(unsigned linha, unsigned coluna, const T &valor);

        /**
         * @brief Retorna uma referência ao elemento na posição especificada.
         * @param linha Linha do elemento.
         * @param coluna Coluna do elemento.
         * @return Referência ao elemento.
         * @throws std::out_of_range se o índice estiver fora dos limites.
         */
        T &getElemento(unsigned linha, unsigned coluna);

        /**
         * @brief Redimensiona a matriz e garante que os elementos existentes mantenham suas posições.
         * @param novasLinhas Novo número de linhas.
         * @param novasColunas Novo número de colunas.
         * @param valorPadrao Valor a ser atribuído aos novos elementos.
         * @param mapaIndices Dicionário para mapear os índices antigos para os novos.
         * @throws std::out_of_range se os índices estiverem fora dos limites.
         */
        void redimensionar(unsigned novasLinhas, unsigned novasColunas, const T &valorPadrao = T(), Dicionario<unsigned> &mapaIndices = Dicionario<unsigned>());

        /**
         * @brief Redimensiona a matriz e garante que os elementos existentes mantenham suas posições.
         * @param novasLinhasColunas Novo número de  linhas e colunas (matriz quadrada).
         * @param valorPadrao Valor a ser atribuído aos novos elementos.
         * @throws std::out_of_range se os índices estiverem fora dos limites.
         */
        void redimensionar(unsigned novasLinhasColunas, const T &valorPadrao = T());

        /**
         * @brief Acesso a uma linha por índice.
         * @param indice Índice da linha.
         * @return Referência a linha.
         * @throws std::out_of_range se o índice estiver fora dos limites.
         */
        T &operator[](unsigned indice);

        /**
         * @brief Acesso constante a uma linha por índice.
         * @param indice Índice do linha.
         * @return Referência constante a linha.
         * @throws std::out_of_range se o índice estiver fora dos limites.
         */
        const T &operator[](unsigned indice) const;

        /**
         * @brief Retorna o número de linhas da matriz.
         * @return Número de linhas.
         */
        unsigned getLinhas() const;

        /**
         * @brief Retorna o número de colunas da matriz.
         * @return Número de colunas.
         */
        unsigned getColunas() const;

        /**
         * @brief Retorna o número de elementos atualmente armazenados.
         * @return Tamanho da matriz.
         */
        unsigned tamanho() const;

        /**
         * @brief Retorna a capacidade atual do buffer interno.
         * @return Capacidade da matriz.
         */
        unsigned capacidade() const;
    };

} // namespace TADS

#include "../src/Matriz.tpp"
