#include "Tema.h"
Tema::Tema() : _id(0), _nome(""), _tipo(TipoTema::Academico) {}
Tema::Tema(unsigned id, std::string nome, TipoTema tipo) : _id(id), _nome(nome), _tipo(tipo) {}

unsigned Tema::getId() const { return _id; }
std::string Tema::getNome() const { return _nome; }
TipoTema Tema::getTipo() const { return _tipo; }