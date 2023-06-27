#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <iostream>
#include <vector>
#include "Canal.h"


class Servidor{
private:
    int usuarioDonoId;
    std::string nome;
    std::string descricao;
    std::string codigoConvite; //codigo para entrar no servidor

    std::vector<Canal> canais;
    std::vector<int> participantesIDs; //lista de usuarios que já estão no servidor
public:
//specials
    Servidor();
    //Servidor(int usuarioDonoId, std::string nome);
    Servidor(int usuarioDonoId, std::string nome, std::string descricao, std::string codigoConvite);
    ~Servidor();

//gets
    int getparticpantes();
    int getDonoID();
    std::string getNome();
    std::string getDescricao();
    std::string getCodigoConvite();
    std::vector<Canal> getCanais();
    std::vector<int> getParticipantesIDs();

//sets
    void setDonoID(int usuarioDonoId);
    void setNome(std::string nome);
    void setDescricao(std::string descricao);
    void setCodigoConvite(std::string codigoConvite);
    void setCanais(std::vector<Canal> canais);
    void setParticipantesIDs(std::vector<int> participantesIDs);

};

#endif