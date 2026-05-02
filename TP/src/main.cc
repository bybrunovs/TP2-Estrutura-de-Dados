#include <iostream>
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
        std::string linha;
        while (getline(std::cin, linha))
        {
            std::string token;
            std::stringstream ss(linha);
            ss >> token;

            //Selecinar o modo de armazenamento
            if (token.compare("A") == 0)
            {
            }
            // Cadastra um novo tema
            else if (token.compare("T") == 0)
            {
            }
            // Cadastra um novo usuário
            else if (token.compare("U") == 0)
            {
            }
            // Usuário id_1 segue usuário id_2
            else if (token.compare("S") == 0)
            {
            }
            // Usuário id_1 deixa de seguir usuário id_2
            else if (token.compare("R") == 0)
            {
            }
            // Lista os temas associados ao usuário
            else if (token.compare("LT") == 0)
            {
            }
            // Lista os usuários que seguem <id_usuario>
            else if (token.compare("LC") == 0)
            {
            }
            // Lista os usuários seguidos por <id_usuario>
            else if (token.compare("LS") == 0)
            {
            }
            // Lista os amigos de <id_usuario>
            else if (token.compare("LA") == 0)
            {
            }
            // Consulta a relação de seguimento entre dois usuário
            else if (token.compare("Q") == 0)
            {
            }
            // Verifica se o usuário possui interesse no tema
            else if (token.compare("G") == 0)
            {
            }
            // Consulta a popularidade do tema,
            else if (token.compare("F") == 0)
            {
            }
            else
            {
            }
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