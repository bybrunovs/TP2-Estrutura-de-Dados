/**
 * @file Usuario.h
 * @author Bruno Vieira
 * @brief Representa um usuário na rede social.
 * @version 0.1
 * @date 2025-05-02
 */

#include <string>

class Usuario
{
private:
    unsigned _id;
    unsigned _idade;
    std::string _nome;

public:
    Usuario();
    Usuario(unsigned id, unsigned idade, std::string nome);
    ~Usuario();

    std::string getNome() const;
    unsigned getId() const;
    unsigned getIdade() const;
};
