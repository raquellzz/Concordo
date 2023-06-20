#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <iostream>

class Mensagem{
private:
    int enviadaPor;
    std::string dataHora;
    std::string conteudo;
public:
//specials
    Mensagem();
    Mensagem(int enviadaPor, std::string dataHora, std::string conteudo);
    ~Mensagem();

//gets
    int getEnviadaPor();
    std::string getDataHora();
    std::string getConteudo();

//sets
    void setEnviadaPor(int enviadaPor);
    void setDataHora(std::string dataHora);
    void setConteudo(std::string conteudo);

};

#endif