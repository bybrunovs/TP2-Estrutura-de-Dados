#include "Usuario.h"

Usuario::Usuario() : _id(0), _idade(0), _nome("") {}
Usuario::Usuario(unsigned id, unsigned idade, std::string nome) : _id(id), _idade(idade), _nome(nome) {}

std::string Usuario::getNome() const { return _nome; }
unsigned Usuario::getId() const { return _id; }
unsigned Usuario::getIdade() const { return _idade; }