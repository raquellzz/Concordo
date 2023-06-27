/**
 * @file Usuario.cpp
 * @brief Implementação dos métodos da classe Usuário.
 * 
 */

#include "Usuario.h"
#include <iostream>



/**
 * @brief Construtor de usuário vazio
 * 
 */
Usuario::Usuario(){
    this->id = 0;
    this->nome = "";
    this->email = "";
    this->senha = "";
}

/**
 * @brief Construtor de usuário com atributos
 * 
 * @param id 
 * @param email 
 * @param senha 
 * @param nome 
 */
Usuario::Usuario(int id, std::string email, std::string senha, std::string nome){
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

//destrutor
Usuario::~Usuario(){
    
}

/**
 * @brief Função que retorna o id do usuário
 * 
 * @return int 
 */
int Usuario::getId(){
    return this->id;
}

/**
 * @brief Função que retorna o nome do usuário
 * 
 * @return std::string 
 */
std::string Usuario::getNome(){
    return this->nome;
}

/**
 * @brief Função que retorna o email do usuário
 * 
 * @return std::string 
 */
std::string Usuario::getEmail(){
    return this->email;
}

/**
 * @brief Função que retorna a senha do usuário
 * 
 * @return std::string 
 */
std::string Usuario::getSenha(){
    return this->senha;
}

/**
 * @brief Função que define o id do usuário
 * 
 * @param id 
 */
void Usuario::setId(int id){
    this->id = id;
}

/**
 * @brief Função que define o nome do usuário
 * 
 * @param nome 
 */
void Usuario::setNome(std::string nome){
    this->nome = nome;
}

/**
 * @brief Função que define o email do usuário
 * 
 * @param email 
 */
void Usuario::setEmail(std::string email){
    this->email = email;
}


/**
 * @brief Função que define a senha do usuário
 * 
 * @param senha 
 */
void Usuario::setSenha(std::string senha){
    this->senha = senha;
}
