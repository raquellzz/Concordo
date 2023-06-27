/**
 * @file CanalTexto.cpp
 * 
 * @brief Implementação dos métodos da classe CanalTexto
 * 
 */

#include "CanalTexto.h"
#include <iostream>

/**
 * @brief Construtor vazio de um canal de texto
 * 
 */
CanalTexto::CanalTexto(){
    this->nome = "";
}

/**
 * @brief Construtor de canal de texto com atributos
 * 
 * @param nome 
 */
CanalTexto::CanalTexto(std::string nome){
    this->nome = nome;
}


