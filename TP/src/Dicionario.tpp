namespace TADS
{
    template <typename T>
    Dicionario<T>::Dicionario() {}

    template <typename T>
    Dicionario<T>::Dicionario(unsigned capacidade)
    {
        this->_valores = Vector<T>(capacidade);
    }

    template <typename T>
    void Dicionario<T>::adicionar(const T &valor)
    {
        this->_valores.push_back(valor);
    }

    template <typename T>
    void Dicionario<T>::remover(const unsigned &chave)
    {
        this->_valores.deleteElemento(chave);
    }
    template <typename T>
    bool Dicionario<T>::contem(const unsigned &chave) const
    {
        return this->_valores.contains(chave);
    }

    template <typename T>
    T &Dicionario<T>::getValor(const unsigned &chave)
    {
        return this->_valores.getElemento(chave);
    }

    template <typename T>
    const T &Dicionario<T>::getValor(const unsigned &chave) const
    {
        return this->_valores.getElemento(chave);
    }

    template <typename T>
    void Dicionario<T>::atualizar(const unsigned &chave, const T &novoValor)
    {
        this->_valores.setElemento(chave, novoValor);
    }

    template <typename T>
    unsigned Dicionario<T>::tamanho() const
    {
        return this->_valores.tamanho();
    }

    template <typename T>
    bool Dicionario<T>::vazio() const
    {
        return this->_valores.tamanho() == 0;
    }
    template <typename T>
    T &Dicionario<T>::operator[](const unsigned &chave)
    {
        return this->_valores.getElemento(chave);
    }

    template <typename T>
    const T &Dicionario<T>::operator[](const unsigned &chave) const
    {
        return this->_valores.getElemento(chave);
    }
} // namespace TADS
