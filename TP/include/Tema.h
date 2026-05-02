/**
 * @file Tema.h
 * @author Bruno Vieira
 * @brief Representa um tema de interesse na rede social.
 * @version 0.1
 * @date 2025-05-02
 */

#include <string>

enum class TipoTema
{
    Academico = 'A',
    Pessoal = 'P'
};

class Tema
{
private:
    unsigned _id;
    std::string _nome;
    TipoTema _tipo;

public:
    Tema();
    Tema(unsigned id, std::string nome, TipoTema tipo);
    ~Tema();

    unsigned getId() const;
    std::string getNome() const;
    TipoTema getTipo() const;
};
