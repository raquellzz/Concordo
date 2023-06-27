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
    std::vector<std::string>emails;
    std::vector<Servidor> servidores;
    int usuarioLogadoId = -1;
    std::string servidorAtual;
    std::string canalAtual;
    int id = 0;
public:
    void increaseId();
    int getId();
    int getusuarios();
    int getServidores();
    std::string verify_login(int usuarioLogadoId);
    std::string quit();
    std::string create_user (const std::string email, const std::string senha, const std::string nome);
    std::string login (std::string email, std::string senha);
    std::string disconnect();
    std::string create_server (std::string nome);
    std::string set_server_desc (std::string nome, std::string descricao);
    std::string set_server_invite_code (std::string nome, std::string codigo);
    std::string list_servers();
    std::string remove_server (std::string nome);
    std::string enter_server (std::string nome, std::string codigo);
    std::string leave_server();
    std::string list_participants();
};

#endif