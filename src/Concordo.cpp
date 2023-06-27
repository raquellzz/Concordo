/**
 * @file Concordo.cpp
 * @author Raquel Freire
 * @brief Função main que faz o programa funcionar.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sistema.h"
#include "Executor.h"

int main(){
    
    Sistema sistema; //!< Armazena o sistema que será usado
    Executor executor(&sistema); //!< Armazena os dados de um executor em função do sistema
    executor.iniciar(); //!< Inicia o programa
    return 0;
}