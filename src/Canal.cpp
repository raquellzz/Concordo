/**
 * @file Canal.cpp
 * @brief Implementação dos métodos da classe Canal.
 * 
 */

#include "Canal.h"



/**
 * @brief Função que retorna o nome do canal
 * 
 * @return std::string 
 */
std::string Canal::getNome() {
    return this->nome;
}


/**
 * @brief Função que define o nome do canal
 * 
 * @param nome 
 */
void Canal::setNome(std::string nome) {
    this->nome = nome;
}

 
