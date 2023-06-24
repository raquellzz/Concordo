#include <string>
#include <iostream>
#include <vector>
#include "Canal.h"
#include "Servidor.h"

Servidor::Servidor(){
    this->usuarioDonoId = -1;
    this->nome = "";
    this->descricao = "";
    this->codigoConvite = "";
}


Servidor::Servidor(int usuarioDonoId, std::string nome, std::string descricao, std::string codigoConvite){
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->descricao = descricao;
    this->codigoConvite = codigoConvite;
}

Servidor::~Servidor(){
}

int Servidor::getDonoID(){
    return this->usuarioDonoId;
}

std::string Servidor::getNome(){
    return this->nome;
}

std::string Servidor::getDescricao(){
    return this->descricao;
}

std::string Servidor::getCodigoConvite(){
    return this->codigoConvite;
}

std::vector<Canal> Servidor::getCanais(){
    return this->canais;
}

std::vector<int> Servidor::getParticipantesIDs(){
    return this->participantesIDs;
}

void Servidor::setDonoID(int usuarioDonoId){
    this->usuarioDonoId = usuarioDonoId;
}

void Servidor::setNome(std::string nome){
    this->nome = nome;
}

void Servidor::setDescricao(std::string descricao){
    this->descricao = descricao;
}

void Servidor::setCodigoConvite(std::string codigoConvite){
    this->codigoConvite = codigoConvite;
}

void Servidor::setCanais(std::vector<Canal> canais){
    this->canais = canais;
}

void Servidor::setParticipantesIDs(std::vector<int> participantesIDs){
    this->participantesIDs = participantesIDs;
}
