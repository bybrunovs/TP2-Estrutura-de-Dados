#include <string>
#include "No.h"

namespace TADS
{

    No::No() : _id(0), _tipo(TipoNo::Usuario) {}

    No::No(unsigned id, TipoNo tipo) : _id(id), _tipo(tipo) {}

    unsigned No::getId() const { return _id; }
    TipoNo No::getTipo() const { return _tipo; }

} // namespace TADS
