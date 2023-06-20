#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <iostream>
#include <vector>
#include "Canal.h"
#include "Usuario.h"
#include "Mensagem.h"
#include "Servidor.h"

class Sistema{
private:
    std::vector<Usuario> usuarios;
    std::vector<Servidor> servidores;
    int usuarioLogadoId;
    std::string servidorAtual;
    std::string canalAtual;
    int *id = 0;
public:
    std::string quit();
    std::string create_user (int *id, std::string email, std::string senha, std::string nome);
    std::string login (std::string email, std::string senha);
    std::string disconnect();
    std::string create_server (std::string nome);
    std::string set_server_desc (std::string nome, std::string descricao);
    std::string set_server_invite_code (std::string nome, std::string codigo);
    std::string list_servers();
};

#endif