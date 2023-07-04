/**
 * @file CanalTexto.cpp
 * 
 * @brief Implementação dos métodos da classe CanalTexto
 * 
 */

#include "CanalTexto.h"
#include <iostream>


/**
 * @brief Construtor de canal de texto com atributos
 * 
 * @param nome 
 */
CanalTexto::CanalTexto(std::string nome){
    this->nome = nome;
    this->mensagens = std::vector<Mensagem>();
}

/**
 * @brief Função que retorna o tipo de um canal de texto
 * 
 * @return std::string 
 */
std::string CanalTexto::getTipo(){
    return "texto";
}

/**
 * @brief Função que retorna a quantidade de mensagens de um canal de texto
 * 
 * @return int 
 */
int CanalTexto::getMensagensSize(){
    return this->mensagens.size();
}

/**
 * @brief Função que retorna todas as mensagens de um canal de texto
 * 
 * @return std::vector<Mensagem> 
 */
std::vector<Mensagem> CanalTexto::getMensagens(){
    return this->mensagens;
}

/**
 * @brief Função que altera todas as mensagens de um canal de texto
 * 
 * @param mensagens 
 */
void CanalTexto::setMensagens(std::vector<Mensagem> mensagens){
    this->mensagens = mensagens;
}

/**
 * @brief Função que adiciona uma mensagem a um canal de texto
 * 
 * @param mensagem 
 */
void CanalTexto::addMensagem(Mensagem mensagem){
    this->mensagens.push_back(mensagem);
}

