/**
 * @file Sistema.cpp
 * 
 * @brief Implementação dos métodos da classe Sistema.
 * 
 */

#include "Sistema.h"
#include <iostream>
#include "Usuario.h"
#include <vector>


/**
 * @brief Função para aumentar o último id
 * 
 */
void Sistema::increaseId(){
    id++;
}

/**
 * @brief Função que retorna o último id
 * 
 * @return int 
 */
int Sistema::getId(){
    return id;
}

/**
 * @brief Função que retorna a quantidade de usuários cadastrados
 * 
 * @return int 
 */
int Sistema::getusuarios(){
    return usuarios.size();
}

/**
 * @brief Função que retorna a quantidade de servidores criados
 * 
 * @return int 
 */
int Sistema::getServidores(){
    return servidores.size();
}

/**
 * @brief Função que verifica se há um usuário logado
 * 
 * @param usuarioLogadoId 
 * @return std::string 
 */
std::string Sistema::verify_login(int usuarioLogadoId){
    if (usuarioLogadoId == -1){
        return "Nenhum usuário logado!";
    }
    return "";
}

/**
 * @brief Função que representa o comando para sair do sistema
 * 
 * @return std::string 
 */
std::string Sistema::quit(){
    return "Saindo do Concordo...";
}

/**
 * @brief Função que representa o comando para criar usuário
 * 
 * @param email 
 * @param senha 
 * @param nome 
 * @return std::string 
 */
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
    return "Usuário criado com sucesso!";
}

/**
 * @brief Função que representa o comando para fazer login no sistema
 * 
 * @param email 
 * @param senha 
 * @return std::string 
 */
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

/**
 * @brief Função que representa o comando para desconectar o usuário do sistema
 * 
 * @return std::string 
 */
std::string Sistema::disconnect(){
    usuarioLogadoId = -1;
    return "Desconectado com sucesso!";
}

/**
 * @brief Função que representa o comando para criar um servidor
 * 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::create_server (std::string nome){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            return "Servidor já existe!";
        }
    }
    Servidor novoServidor(usuarioLogadoId, nome, "", "");
    
    servidores.push_back(novoServidor);
    servidores[getServidores()-1].addParticipantesIDs(usuarioLogadoId);
    servidorAtual = novoServidor.getNome();
    return "Servidor criado com sucesso!";
}

/**
 * @brief Função que representa o comando para definir a descrição de um servidor
 * 
 * @param nome 
 * @param descricao 
 * @return std::string 
 */
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

/**
 * @brief Função que representa o comando para definir o código de convite de um servidor
 * 
 * @param nome 
 * @param codigo 
 * @return std::string 
 */
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

/**
 * @brief Função que representa o comando para listar os servidores existentes no sistema
 * 
 * @return std::string 
 */
std::string Sistema::list_servers(){
    verify_login(usuarioLogadoId);
    std::string lista = "";
    for (int i = 0; i < getServidores(); i++){
        if(i == getServidores()-1){
            lista += servidores[i].getNome();
            return lista;
        }
        lista += servidores[i].getNome() + "\n";
    }
    return lista;
}

/**
 * @brief Função que representa o comando para remover um servidor do sistema
 * 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::remove_server(std::string nome){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if (servidores[i].getDonoID() == usuarioLogadoId){
                servidores.erase(servidores.begin() + i);
                servidorAtual = "";
                return "Servidor removido com sucesso!";
            }
            else{
                return "Você não é o dono do servidor!";
            }
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para entrar em um servidor existente
 * 
 * @param nome 
 * @param codigo 
 * @return std::string 
 */
std::string Sistema::enter_server(std::string nome, std::string codigo){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if (servidores[i].getCodigoConvite() == codigo){
                servidorAtual = nome;
                servidores[i].addParticipantesIDs(usuarioLogadoId);
                return "Entrou no servidor com sucesso!";
            }
            else{
                return "Código de convite inválido!";
            }
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para deslogar de um servidor
 * 
 * @return std::string 
 */
std::string Sistema::leave_server(){
    verify_login(usuarioLogadoId);
    servidorAtual = "";
    return "Saindo do servidor...";
}

/**
 * @brief Função que representa o comando para listar os participantes do servidor atual
 * 
 * @return std::string 
 */
std::string Sistema::list_participants(){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == servidorAtual){
            std::string lista = "";
            for (int j = 0; j < servidores[i].getparticpantes(); j++){
                for(int k = 0; k < getusuarios(); k++){
                    if(usuarios[k].getId() == servidores[i].getParticipantesIDs()[j]){
                        if(k == getusuarios() - 1){
                            lista += usuarios[k].getNome();
                            break;
                        }
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