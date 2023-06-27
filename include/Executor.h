/**
 * @file Executor.h
 * 
 * @brief Classe que executa as funções do sistema.
 * 
 * 
 */

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include <iostream>
#include <vector>
#include "Sistema.h"
#include <fstream>


class Executor{
private:
    Sistema *sistema; //!< Cria o sistema que será utiliazdo na compilação
    
    bool sair = false; //!< Variável booleana para verificar se o sistema deve fechar ou não

public:
    Executor(Sistema *sistema);

    void iniciar();

    std::string LeituraComandos(std::string linha, Sistema *sistema);
};

#endif