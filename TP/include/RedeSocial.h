/**
 * @file RedeSocial.h
 * @author Bruno Vieira
 * @brief Classe que representa a rede social, contendo os grafos de usuários e temas, bem como os dicionários para armazenar as informações dos usuários e temas.
 * @version 0.1
 * @date 2025-05-02
 */

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
    TADS::Dicionario<Usuario> _usuarios; //Armazena os usuários cadastrados, onde a chave é o id do usuário
    TADS::Dicionario<Tema> _temas; //Armazena os temas cadastrados, onde a chave é o id do tema

    TADS::Dicionario<TADS::No> _nosGrafoSocial; // Relaciona vertices do grafo social com o id do usuário, onde a chave é o id do vértice do grafo social   
    TADS::Dicionario<TADS::No> _nosGrafoTemas; // Relaciona vertices do grafo social com o id do usuário ou tema, onde a chave é o id do vértice do grafo de temas   

public:
    RedeSocial();
    ~RedeSocial();
};
