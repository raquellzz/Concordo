/**
 * @file Mensagem.cpp
 * 
 * @brief Implementação dos métodos da classe Mensagem.
 * 
 */

#include "Mensagem.h"
#include <iostream>


/**
 * @brief Construtor vazio de uma mensagem
 * 
 */
Mensagem::Mensagem() {
    this->enviadaPor = 0;
    this->dataHora = "";
    this->conteudo = "";
}

/**
 * @brief Construtor com atributos de uma mensagem
 * 
 * @param enviadaPor 
 * @param dataHora 
 * @param conteudo 
 */
Mensagem::Mensagem(int enviadaPor, std::string dataHora, std::string conteudo) {
    this->enviadaPor = enviadaPor;
    this->dataHora = dataHora;
    this->conteudo = conteudo;
}

/**
 * @brief Função que retorna o id do usuário que enviou a mensagem
 * 
 * @return int 
 */
int Mensagem::getEnviadaPor() {
    return this->enviadaPor;
}

/**
 * @brief Função que retorna a data e hora da mensagem enviada
 * 
 * @return std::string 
 */
std::string Mensagem::getDataHora() {
    return this->dataHora;
}

/**
 * @brief Função que retorna o conteúdo da mensagem enviada
 * 
 * @return std::string 
 */
std::string Mensagem::getConteudo() {
    return this->conteudo;
}

/**
 * @brief Função que define o id do usuário que enviou a mensagem
 * 
 * @param enviadaPor 
 */
void Mensagem::setEnviadaPor(int enviadaPor) {
    this->enviadaPor = enviadaPor;
}

/**
 * @brief Função que define a data e hora da mensagem enviada
 * 
 * @param dataHora 
 */
void Mensagem::setDataHora(std::string dataHora) {
    this->dataHora = dataHora;
}

/**
 * @brief Função que define o conteúdo da mensagem enviada
 * 
 * @param conteudo 
 */
void Mensagem::setConteudo(std::string conteudo) {
    this->conteudo = conteudo;
}