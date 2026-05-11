#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

#include "RedeSocial.h"

// O programa lê uma linha inicial M seguida por várias linhas de comando
// O código principal faz parsing dessas linhas e chama os métodos
// de AnaliseCarteiras para executar a lógica do sistema.

// começa a contar  o tempo de execucao
// auto start = std::chrono::high_resolution_clock::now();

int main(int argc, char *argv[])
{
    try
    {
        // inicilaizando a rede social
        RedeSocial redeSocial;

        // lendo linha por linha até o final da entrada
        std::string linha;
        while (getline(std::cin, linha))
        {
            std::string token;
            std::stringstream ss(linha);
            ss >> token;

            // Selecinar o modo de armazenamento
            if (token.compare("A") == 0)
            {
                char ModoArmazenamento;
                ss >> ModoArmazenamento;
                redeSocial.mudarRepresentacaoGrafos(ModoArmazenamento);
            }
            // Cadastra um novo tema
            else if (token.compare("T") == 0)
            {
                std::string nomeTema;
                char tipoTema;
                ss >> nomeTema >> tipoTema;
                redeSocial.adicionarTema(nomeTema, tipoTema);
            }
            // Cadastra um novo usuário
            else if (token.compare("U") == 0)
            {
                std::string nomeUsuario;
                unsigned idadeUsuario;
                ss >> nomeUsuario >> idadeUsuario;

                redeSocial.adicionarUsuario(nomeUsuario, idadeUsuario);
                unsigned idTema;
                for (size_t i = 0; ss >> idTema; i++)
                {
                    redeSocial.adicionarTemaUsuario(idTema);
                }
            }
            // Usuário id_1 segue usuário id_2
            else if (token.compare("S") == 0)
            {
                unsigned idSeguidor, idSeguido;
                ss >> idSeguidor >> idSeguido;
                redeSocial.seguirUsuario(idSeguidor, idSeguido);
            }
            // Usuário id_1 deixa de seguir usuário id_2
            else if (token.compare("R") == 0)
            {
                unsigned idSeguidor, idSeguido;
                ss >> idSeguidor >> idSeguido;
                redeSocial.deixarSeguirUsuario(idSeguidor, idSeguido);
            }
            // Lista os temas associados ao usuário
            else if (token.compare("LT") == 0)
            {
                unsigned idUsuario;
                ss >> idUsuario;
                redeSocial.listarTemasUsuario(idUsuario);
            }
            // Lista os usuários que seguem <id_usuario>
            else if (token.compare("LC") == 0)
            {
                unsigned idUsuario;
                ss >> idUsuario;
                redeSocial.listarSeguidores(idUsuario);
            }
            // Lista os usuários seguidos por <id_usuario>
            else if (token.compare("LS") == 0)
            {
                unsigned idUsuario;
                ss >> idUsuario;
                redeSocial.listarSeguidos(idUsuario);
            }
            // Lista os amigos de <id_usuario>
            else if (token.compare("LA") == 0)
            {
                unsigned idUsuario;
                ss >> idUsuario;
                redeSocial.listarAmigos(idUsuario);
            }
            // Consulta a relação de seguimento entre dois usuário
            else if (token.compare("Q") == 0)
            {
                unsigned idUsuario1, idUsuario2;
                ss >> idUsuario1 >> idUsuario2;
                redeSocial.consultarRelacaoSeguimento(idUsuario1, idUsuario2);
            }
            // Verifica se o usuário possui interesse no tema
            else if (token.compare("G") == 0)
            {
                unsigned idUsuario, idTema;
                ss >> idUsuario >> idTema;
                redeSocial.verificarInteresseUsuarioTema(idUsuario, idTema);
            }
            // Consulta a popularidade do tema
            else if (token.compare("F") == 0)
            {
                unsigned idTema;
                ss >> idTema;
                redeSocial.consultarPopularidadeTema(idTema);
            }
            else
                throw std::invalid_argument("Comando inválido: " + token);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // Calculo tempo de execução
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duracao = end - start;
    // std::cerr << "Tempo da consulta: " << duracao.count() << " s" << std::endl;
    return 0;
}