/**
 * @file RedeSocial.h
 * @author Bruno Vieira
 * @brief Classe que representa a rede social, contendo os grafos de usuários e temas, bem como os dicionários para armazenar as informações dos usuários e temas.
 * @version 0.1
 * @date 2025-05-02
 */

#pragma once

#include "Grafo.h"
#include "Dicionario.h"
#include "No.h"
#include "Tema.h"
#include "Usuario.h"

class RedeSocial
{
private:
    TADS::Grafo _grafoSocial;
    TADS::Grafo _grafoTemas;
    TADS::Dicionario<Usuario> _usuarios; // Armazena os usuários cadastrados, onde a chave é o id do usuário
    TADS::Dicionario<Tema> _temas;       // Armazena os temas cadastrados, onde a chave é o id do tema

    // no grafo social o id do vertice é o id do usuário
    TADS::Dicionario<TADS::No> _nosGrafoTemas; // Relaciona vertices do grafo social com o id do usuário ou tema, onde a chave é o id do vértice do grafo de temas

    unsigned _proximoIdUsuario = 0; // Armazena o próximo id disponível para um novo usuário
    unsigned _proximoIdTema = 0;    // Armazena o próximo id disponível para um novo
public:
    RedeSocial();
    ~RedeSocial();

    void mudarRepresentacaoGrafos(char ModoArmazenamento);

    void adicionarTema(const std::string &nomeTema, char tipoTema);

    void adicionarUsuario(const std::string &nomeUsuario, unsigned idadeUsuario);

    void adicionarTemaUsuario(unsigned idTema);

    void seguirUsuario(unsigned idSeguidor, unsigned idSeguido);

    void deixarSeguirUsuario(unsigned idSeguidor, unsigned idSeguido);

    void listarTemasUsuario(unsigned idUsuario);

    void listarSeguidores(unsigned idUsuario);

    void listarSeguidos(unsigned idUsuario);

    void listarAmigos(unsigned idUsuario);

    void consultarRelacaoSeguimento(unsigned idUsuario1, unsigned idUsuario2);

    void verificarInteresseUsuarioTema(unsigned idUsuario, unsigned idTema);

    void consultarPopularidadeTema(unsigned idTema);
};
