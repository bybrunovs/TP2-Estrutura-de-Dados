/**
 * @file No.h
 * @author Bruno Vieira
 * @brief TAD que representa um vertice em um grafo
 * @version 0.1
 * @date 2025-05-02
 */

#pragma once

#include <string>

namespace TADS
{

    enum class TipoNo {
        Usuario,
        Tema
    };
    class No
    {
    private:
        unsigned _id;
        TipoNo _tipo;

    public:
        No();
        No(unsigned id, TipoNo tipo);
        ~No() = default;

        unsigned getId() const;
        TipoNo getTipo() const;
    };

} // namespace TADS
