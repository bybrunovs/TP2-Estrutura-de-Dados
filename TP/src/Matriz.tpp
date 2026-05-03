namespace TADS
{
    template <typename T>
    Matriz<T>::Matriz() : _linhas(0), _colunas(0)
    {
    }

    template <typename T>
    Matriz<T>::Matriz(unsigned linhas, unsigned colunas, const T &valorPadrao)
    {
        TADS::Vector<T> dados(linhas * colunas, valorPadrao);
        this->_linhas = linhas;
        this->_colunas = colunas;
        this->_dados = dados;
    }

    template <typename T>
    Matriz<T>::Matriz(unsigned linhasColunas, const T &valorPadrao)
    {
        TADS::Vector<T> dados(linhasColunas * linhasColunas, valorPadrao);
        this->_linhas = linhasColunas;
        this->_colunas = linhasColunas;
        this->_dados = dados;
    }

    template <typename T>
    void Matriz<T>::setElemento(unsigned linha, unsigned coluna, const T &valor)
    {
        if (linha > this->_linhas || coluna > this->_colunas)
        {
            throw std::out_of_range("Índice de matriz fora dos limites");
        }
        this->_dados.setElemento(linha * this->_colunas + coluna, valor);
    }

    template <typename T>
    T &Matriz<T>::getElemento(unsigned linha, unsigned coluna)
    {
        if (linha > this->_linhas || coluna > this->_colunas)
        {
            throw std::out_of_range("Índice de matriz fora dos limites");
        }
        return this->_dados.getElemento(linha * this->_colunas + coluna);
    }

    template <typename T>
    void Matriz<T>::redimensionar(unsigned novasLinhas, unsigned novasColunas, const T &valorPadrao, Dicionario<unsigned> &mapaIndices)
    {
        Vector<T> novosDados(novasLinhas * novasColunas, valorPadrao);

        for (unsigned i = 0; i < this->_linhas; ++i)
        {
            for (unsigned j = 0; j < this->_colunas; ++j)
            {
                unsigned indiceAntigo = i * this->_colunas + j;
                unsigned indiceNovo = i * novasColunas + j;

                if (indiceAntigo < this->_dados.tamanho() && indiceNovo < novosDados.tamanho())
                {
                    novosDados.setElemento(indiceNovo, this->_dados.getElemento(indiceAntigo));
                    mapaIndices.adicionar(indiceAntigo, indiceNovo); // errado
                }
            }
        }

        this->_dados = std::move(novosDados);
        this->_linhas = novasLinhas;
        this->_colunas = novasColunas;
    }

    template <typename T>
    void Matriz<T>::redimensionar(unsigned novasLinhasColunas, const T &valorPadrao)
    {
        Vector<T> novosDados(novasLinhasColunas * novasLinhasColunas, valorPadrao);

        for (unsigned i = 0; i < this->_linhas; ++i)
        {
            for (unsigned j = 0; j < this->_colunas; ++j)
            {
                unsigned indiceAntigo = i * this->_colunas + j;
                unsigned indiceNovo = i * novasLinhasColunas + j;

                if (indiceAntigo < this->_dados.tamanho() && indiceNovo < novosDados.tamanho())
                {
                    novosDados.setElemento(indiceNovo, this->_dados.getElemento(indiceAntigo));
                }
            }
        }

        this->_dados = std::move(novosDados);
        this->_linhas = novasLinhasColunas;
        this->_colunas = novasLinhasColunas;
    }

    template <typename T>

    T &Matriz<T>::operator[](unsigned indice)
    {
        return this->_dados.getElemento(indice);
    }

    template <typename T>

    const T &Matriz<T>::operator[](unsigned indice) const
    {
        return this->_dados.getElemento(indice);
    }

    template <typename T>
    unsigned Matriz<T>::getLinhas() const
    {
        return this->_linhas;
    }

    template <typename T>
    unsigned Matriz<T>::getColunas() const
    {
        return this->_colunas;
    }

    template <typename T>
    unsigned Matriz<T>::tamanho() const
    {
        return this->_dados.tamanho();
    }

    template <typename T>
    unsigned Matriz<T>::capacidade() const
    {
        return this->_dados.capacidade();
    }
} // namespace TADS