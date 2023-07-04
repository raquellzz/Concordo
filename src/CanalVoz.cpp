/**
 * @file CanalVoz.cpp
 * @brief Implementação dos métodos da classe CanalVoz
 * 
 */

#include "CanalVoz.h"
#include <iostream>

/**
 * @brief Construtor de um canal de voz
 * 
 * @param nome 
 */
CanalVoz::CanalVoz(std::string nome){
    this->nome = nome;
    this->ultimaMensagem = Mensagem();
}

/**
 * @brief Função que retorna o tipo de um canal de voz
 * 
 * @return std::string 
 */
std::string CanalVoz::getTipo(){
    return "voz";  
}

/**
 * @brief Função que retorna a última mensagem enviada no canal de voz
 * 
 * @return Mensagem 
 */
Mensagem CanalVoz::getUltimaMensagem(){
    return ultimaMensagem;
}

/**
 * @brief Função que altera a última mensagem enviada no canal de voz
 * 
 * @param ultimaMensagem 
 */
void CanalVoz::setUltimaMensagem(Mensagem ultimaMensagem){
    this->ultimaMensagem = ultimaMensagem;

}

