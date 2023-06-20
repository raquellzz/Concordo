#include "CanalTexto.h"
#include <iostream>

CanalTexto::CanalTexto(){
    this->nome = "";
}

CanalTexto::CanalTexto(std::string nome){
    this->nome = nome;
}

CanalTexto::~CanalTexto(){
}

