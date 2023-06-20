#include "Sistema.h"

std::string Sistema::quit(){
    return "Saindo do Concordo...";
}

std::string Sistema::create_user (int *id, std::string email, std::string senha, std::string nome){
    if(email == "" || senha == "" || nome == ""){
        return "Dados inválidos.";
    }
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getEmail() == email){
            return "Usuário já existe.";
        }
    }
    Usuario novoUsuario(*id, email, senha, nome);
    usuarios.push_back(novoUsuario);
    (*id)++;
    return "Usuário criado com sucesso!";
}

std::string Sistema::login (std::string email, std::string senha){
    for (int i = 0; i < usuarios.size(); i++){
        if (usuarios[i].getEmail() == email){
            if (usuarios[i].getSenha() == senha){
                usuarioLogadoId = usuarios[i].getId();
                return "Login efetuado com sucesso!";
            }
            else{
                return "Senha incorreta!";
            }
        }
    }
    return "Usuário não encontrado!";
}