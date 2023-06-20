#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario{
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;
    public:
        //specials
        Usuario();
        Usuario(int id, std::string nome, std::string email, std::string senha);
        ~Usuario();

        //gets
        int getId();
        std::string getNome();
        std::string getEmail();
        std::string getSenha();

        //sets
        void setId(int id);
        void setNome(std::string nome);
        void setEmail(std::string email);
        void setSenha(std::string senha);
};

#endif