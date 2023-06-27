#include "Canal.h"

//construtor vazio
Canal::Canal() {
    this->nome = "";
}

//construtor com atributos
Canal::Canal(std::string nome) {
    this->nome = nome;
}


//função que retorna o nome do canal
std::string Canal::getNome() {
    return this->nome;
}

//função que define o nome do canal
void Canal::setNome(std::string nome) {
    this->nome = nome;
}