#include <string>
#include <iostream>
#include <vector>
#include "Executor.h"

Executor::Executor(Sistema *sistema){
    this->sistema = sistema;
    this->sair = false;
}

void Executor::iniciar(){
    while(this->sair != true){
        std::string linha;
        std::getline(std::cin, linha);
        std::cout << LeituraComandos(linha, sistema) << std::endl;
    }
}


std::string Executor::LeituraComandos(std::string linha, Sistema *sistema){
    std::string comando;
    for(auto c: linha){
        if(c == ' '){
            break;
        }
        comando += c;
    }
    int com = 0;
    std::string resto = "";
    for(auto c: linha){
        if(com == 1){
            resto += c;
        }
        if(c == ' '){
            com = 1;
        }
    }
    if(comando == "quit"){
        this->sair = true;
        return sistema->quit();
    }
    else if(comando == "create-user"){
        std::string email = "";
        std::string senha = "";
        std::string nome = "";
        int i = 0;
        for(auto c: resto){
            if(c == ' '){
                if(i < 2){
                    i++;
                    continue;
                }
            }
            if(i == 0){
                email += c;
            }
            if(i == 1){
                senha += c;
                // c = "";
            }
            else if(i == 2){
                nome += c;
                // c = "";
            }
            
        }
        return sistema->create_user(email, senha, nome);
    }
    else if(comando == "login"){
        std::string email;
        std::string senha;
        int i = 0;
        for(auto c: resto){
            if(c == ' '){
                i++;
                continue;
            }
            if(i == 0){
                email += c;
            }
            else if(i == 1){
                senha += c;
            }
        }
        return sistema->login(email, senha);
    }
    else if(comando == "disconnect"){
        return sistema->disconnect();
    }
    else if(comando == "create-server"){
        return sistema->create_server(resto);
    }
    else if(comando == "set-server-desc"){
        std::string nome;
        std::string descricao;
        int i = 0;
        for(auto c: resto){
            if(c == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += c;
            }
            else if(i == 1){
                descricao += c;
            }
        }
        return sistema->set_server_desc(nome, descricao);
    }
    else if(comando == "set-server-invite-code"){
        std::string nome;
        std::string codigo;
        int i = 0;
        for(auto c: resto){
            if(c == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += c;
            }
            else if(i == 1){
                codigo += c;
            }
        }
        return sistema->set_server_invite_code(nome, codigo);
    }
    else if(comando == "list-servers"){
        return sistema->list_servers();
    }
    else if(comando == "remove-server"){
        return sistema->remove_server(resto);
    }
    else if(comando == "enter-server"){
        std::string nome;
        std::string codigo;
        int i = 0;
        for(auto c: resto){
            if(c == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += c;
            }
            else if(i == 1){
                codigo += c;
            }
        }
        return sistema->enter_server(nome, codigo);
    }
    else if(comando == "leave-server"){
        return sistema->leave_server();
    }
    else if(comando == "list-participants"){
        return sistema->list_participants();
    }
    return "Comando invalido";
}