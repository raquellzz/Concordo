#include "Usuario.h"
#include <iostream>

//construtor vazio
Usuario::Usuario(){
    this->id = 0;
    this->nome = "";
    this->email = "";
    this->senha = "";
}

//construtor com atributos
Usuario::Usuario(int id, std::string nome, std::string email, std::string senha){
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

//destrutor
Usuario::~Usuario(){
    
}

//função que retorna o id do usuário
int Usuario::getId(){
    return this->id;
}

//função que retorna o nome do usuário
std::string Usuario::getNome(){
    return this->nome;
}

//função que retorna o email do usuário
std::string Usuario::getEmail(){
    return this->email;
}

//função que retorna a senha do usuário
std::string Usuario::getSenha(){
    return this->senha;
}

//função que define o id do usuário
void Usuario::setId(int id){
    this->id = id;
}

//função que define o nome do usuário
void Usuario::setNome(std::string nome){
    this->nome = nome;
}

//função que define o email do usuário
void Usuario::setEmail(std::string email){
    this->email = email;
}

//função que define a senha do usuário
void Usuario::setSenha(std::string senha){
    this->senha = senha;
}
