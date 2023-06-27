#include "Sistema.h"
#include <iostream>
#include "Usuario.h"
#include <vector>

void Sistema::increaseId(){
    id++;
}

int Sistema::getId(){
    return id;
}

int Sistema::getusuarios(){
    return usuarios.size();
}

int Sistema::getServidores(){
    return servidores.size();
}

std::string Sistema::verify_login(int usuarioLogadoId){
    if (usuarioLogadoId == -1){
        return "Nenhum usuário logado!";
    }
    return "";
}

std::string Sistema::quit(){
    return "Saindo do Concordo...";
}

std::string Sistema::create_user (const std::string email, const std::string senha, const std::string nome){
    verify_login(usuarioLogadoId);
    if(email == "" || senha == "" || nome == ""){
        return "Dados inválidos.";
    }
    for(int i = 0; i < getusuarios(); i++){
        if(usuarios[i].getEmail() == email){
            return "Usuário já existe.";
        }
    }
    
    increaseId();
    Usuario novoUsuario(id, email, senha, nome);
    usuarios.push_back(novoUsuario);
    std::cout << usuarios[0].getNome() << "\n";
    return "Usuário criado com sucesso!";
}

std::string Sistema::login (std::string email, std::string senha){
    if(usuarioLogadoId != -1){
        return "Usuário já está logado!";
    }
    for (int i = 0; i < getusuarios(); i++){
        if (usuarios[i].getEmail() == email){
            if (usuarios[i].getSenha() == senha){
                usuarioLogadoId = usuarios[i].getId();
                return "Logado como " + usuarios[i].getEmail() + "!";
            }
            else{
                return "Senha incorreta!";
            }
        }
    }
    return "Usuário não encontrado!";
}

std::string Sistema::disconnect(){
    usuarioLogadoId = -1;
    return "Desconectado com sucesso!";
}

std::string Sistema::create_server (std::string nome){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            return "Servidor já existe!";
        }
    }
    Servidor novoServidor(usuarioLogadoId, nome, "", "");
    
    servidores.push_back(novoServidor);
    return "Servidor criado com sucesso!";
}

std::string Sistema::set_server_desc(std::string nome, std::string descricao){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if(servidores[i].getDonoID() != usuarioLogadoId){
                return "Você não é o dono do servidor!";
            }
            servidores[i].setDescricao(descricao);
            return "Descrição adicionada com sucesso!";
        }
    }
    return "Servidor não encontrado!";
}

std::string Sistema::set_server_invite_code(std::string nome, std::string codigo){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if(servidores[i].getDonoID() != usuarioLogadoId){
                return "Você não é o dono do servidor!";
            }
            servidores[i].setCodigoConvite(codigo);
            return "Código de convite adicionado com sucesso!";
        }
    }
    return "Servidor não encontrado!";
}

std::string Sistema::list_servers(){
    verify_login(usuarioLogadoId);
    std::string lista = "";
    for (int i = 0; i < getServidores(); i++){
        lista += servidores[i].getNome() + "\n";
    }
    return lista;
}

std::string Sistema::remove_server(std::string nome){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if (servidores[i].getDonoID() == usuarioLogadoId){
                servidores.erase(servidores.begin() + i);
                return "Servidor removido com sucesso!";
            }
            else{
                return "Você não é o dono do servidor!";
            }
        }
    }
    return "Servidor não encontrado!";
}

std::string Sistema::enter_server(std::string nome, std::string codigo){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if (servidores[i].getCodigoConvite() == codigo){
                servidorAtual = nome;
                return "Entrou no servidor com sucesso!";
            }
            else{
                return "Código de convite inválido!";
            }
        }
    }
    return "Servidor não encontrado!";
}

std::string Sistema::leave_server(){
    verify_login(usuarioLogadoId);
    servidorAtual = "";
    return "Saindo do servidor...";
}

std::string Sistema::list_participants(){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == servidorAtual){
            std::string lista = "";
            for (int j = 0; j < servidores[i].getparticpantes(); j++){
                for(int k = 0; k < getusuarios(); k++){
                    if(usuarios[k].getId() == servidores[i].getParticipantesIDs()[j]){
                        lista += usuarios[k].getNome() + "\n";
                    }
                }
            }
            if(lista != "")
                return lista;
            return "Não há participantes no servidor!";
        }
    }
    return "Servidor não encontrado!";
}