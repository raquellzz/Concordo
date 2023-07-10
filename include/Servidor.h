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
    std::vector<CanalVoz> canaisVoz; //!< Armazena os canais de voz cadastrados no servidor
    std::vector<CanalTexto> canaisTexto; //!< Armazena os canais de texto cadastrados no servidor  

    std::vector<int> participantesIDs; //!< Lista de usuarios que já estão no servidor
public:
//specials
    Servidor();
    Servidor(int usuarioDonoId, std::string nome, std::string descricao, std::string codigoConvite);

//gets
    int getparticipantes();
    int getDonoID();
    int getCanaisSize();
    int getCanaisVozSize();
    int getCanaisTextoSize();
    std::string getNome();
    std::string getDescricao();
    std::string getCodigoConvite();
    std::vector<Canal> getCanais();
    std::vector<CanalVoz> getCanaisVoz();
    std::vector<CanalTexto> getCanaisTexto();
    std::vector<int> getParticipantesIDs();


//sets
    void setDonoID(int usuarioDonoId);
    void setNome(std::string nome);
    void setDescricao(std::string descricao);
    void setCodigoConvite(std::string codigoConvite);
    void setCanais(std::vector<Canal> canais);
    void setCanaisVoz(std::vector<CanalVoz> canaisVoz);
    void setCanaisTexto(std::vector<CanalTexto> canaisTexto);
    void setParticipantesIDs(std::vector<int> participantesIDs);


    void addParticipantesIDs(int participanteID);
    void addCanalTexto(CanalTexto canal);
    void addCanalVoz(CanalVoz canal);
    void addMensagens_v(Mensagem mensagem, std::string atual);
    void addMensagens_t(Mensagem mensagem, std::string atual);
};

#endif