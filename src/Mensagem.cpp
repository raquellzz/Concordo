#include "Mensagem.h"
#include <iostream>


//construtor vazio
Mensagem::Mensagem() {
    this->enviadaPor = 0;
    this->dataHora = "";
    this->conteudo = "";
}

//construtor com atributos
Mensagem::Mensagem(int enviadaPor, std::string dataHora, std::string conteudo) {
    this->enviadaPor = enviadaPor;
    this->dataHora = dataHora;
    this->conteudo = conteudo;
}


//destrutor
Mensagem::~Mensagem() {
}

//função que retorna o id do usuário que enviou a mensagem
int Mensagem::getEnviadaPor() {
    return this->enviadaPor;
}

//função que retorna a data e hora da mensagem enviada
std::string Mensagem::getDataHora() {
    return this->dataHora;
}

//função que retorna o conteúdo da mensagem enviada
std::string Mensagem::getConteudo() {
    return this->conteudo;
}

//função que define o id do usuário que enviou a mensagem
void Mensagem::setEnviadaPor(int enviadaPor) {
    this->enviadaPor = enviadaPor;
}

//função que define a data e hora da mensagem enviada
void Mensagem::setDataHora(std::string dataHora) {
    this->dataHora = dataHora;
}

//função que define o conteúdo da mensagem enviada
void Mensagem::setConteudo(std::string conteudo) {
    this->conteudo = conteudo;
}