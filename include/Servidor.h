/**
 * @file Servidor.h
 * 
 * @brief Definição da classe Servidor.
 * 
 * @details A classe servidor é responsável por armazenar as informações de um servidor, como seu nome, descrição, código, canais, id do dono e ids dos participantes.
 * 
 * 
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <iostream>
#include <vector>
#include "Canal.h"


/**
 * @brief Classe que representa um servidor do sistema.
 * 
 */
class Servidor{
private:
    int usuarioDonoId;
    std::string nome; //!< Armazena o nome do servidor
    std::string descricao; //!< Armazena a descrição do servidor
    std::string codigoConvite; //!< Armazena o código necessário para entrar no servidor

    std::vector<Canal> canais; //!< Armazena os canais cadastrados no servidor
    std::vector<int> participantesIDs; //!< Lista de usuarios que já estão no servidor
public:
//specials
    Servidor();
    Servidor(int usuarioDonoId, std::string nome, std::string descricao, std::string codigoConvite);

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
    void addParticipantesIDs(int participanteID);

};

#endif