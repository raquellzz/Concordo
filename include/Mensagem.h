/**
 * @file Mensagem.h
 * 
 * @brief Classe que representa as mensagens enviadas no sistema.
 * 
 */

#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <iostream>

class Mensagem{
private:
    int enviadaPor; //!< Armazena o id de quem enviou a mensagem
    std::string dataHora; //!< Armazena a data e o horário em que a mensagem foi enviada
    std::string conteudo; //!< Armazena o conteúdo da mensagem
public:
//specials
    Mensagem();
    Mensagem(int enviadaPor, std::string dataHora, std::string conteudo);

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