/**
 * @file Usuario.h
 * 
 * @brief Classe que representa um usuário do sistema;
 * 
 * @details A classe usuário é responsável por armazenar as informações de um usuário, como seu id, nome, email e senha.
 * 
 * 
 */


#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>



class Usuario{
    private:
        int id; //!< Armazena o id do usuário
        std::string nome; //!< Armazena o nome do usuário
        std::string email; //!< Armazena o email do usuário
        std::string senha; //!< Armazena a senha do usuário
    public:
        ///specials
        Usuario();
        Usuario(int id, std::string email, std::string senha, std::string nome);
        ~Usuario();

        ///gets
        int getId();
        std::string getNome();
        std::string getEmail();
        std::string getSenha();

        ///sets
        void setId(int id);
        void setNome(std::string nome);
        void setEmail(std::string email);
        void setSenha(std::string senha);
};

#endif