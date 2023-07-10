/**
 * @file Servidor.cpp
 * 
 * @brief Implementação dos métodos da classe Servidor.
 * 
 */

#include <string>
#include <iostream>
#include <vector>
#include "Canal.h"
#include "CanalTexto.h"
#include "CanalVoz.h"
#include "Servidor.h"

/**
 * @brief Construtor vazio de servidor
 * 
 */
Servidor::Servidor(){
    this->usuarioDonoId = -1;
    this->nome = "";
    this->descricao = "";
    this->codigoConvite = "";
}

/**
 * @brief Construtor com atributos de servidor
 * 
 * @param usuarioDonoId 
 * @param nome 
 * @param descricao 
 * @param codigoConvite 
 */
Servidor::Servidor(int usuarioDonoId, std::string nome, std::string descricao, std::string codigoConvite){
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->descricao = descricao;
    this->codigoConvite = codigoConvite;
}


/**
 * @brief Função que retorna a quantidade de participantes em um servidor
 * 
 * @return int 
 */
int Servidor::getparticipantes(){
    return this->participantesIDs.size();
}

/**
 * @brief Função que o id do dono de um servidor
 * 
 * @return int 
 */
int Servidor::getDonoID(){
    return this->usuarioDonoId;
}

/**
 * @brief Função que retorna o nome do servidor
 * 
 * @return std::string 
 */
std::string Servidor::getNome(){
    return this->nome;
}

/**
 * @brief Função que retorna a descrição de um servidor
 * 
 * @return std::string 
 */
std::string Servidor::getDescricao(){
    return this->descricao;
}

/**
 * @brief Função que retorna o código de convite de um servidor
 * 
 * @return std::string 
 */
std::string Servidor::getCodigoConvite(){
    return this->codigoConvite;
}

/**
 * @brief Função que retorna os canais de um servidor
 * 
 * @return std::vector<Canal> 
 */
std::vector<Canal> Servidor::getCanais(){
    return this->canais;
}

/**
 * @brief Função que retorna os canais de voz de um servidor
 * 
 * @return std::vector<CanalVoz> 
 */
std::vector<CanalVoz> Servidor::getCanaisVoz(){
    return this->canaisVoz;
}

/**
 * @brief Função que retorna os canais de texto de um servidor
 * 
 * @return std::vector<CanalTexto> 
 */
std::vector<CanalTexto> Servidor::getCanaisTexto(){
    return this->canaisTexto;
}

/**
 * @brief Função que retorna os ids dos participantes de um servidor
 * 
 * @return std::vector<int> 
 */
std::vector<int> Servidor::getParticipantesIDs(){
    return this->participantesIDs;
}

/**
 * @brief Função que retorna a quantidade de canais de um servidor
 * 
 * @return int 
 */
int Servidor::getCanaisSize(){
    return this->canais.size();
}

/**
 * @brief Função que retorna a quantidade de canais de voz de um servidor
 * 
 * @return int
 */
int Servidor::getCanaisVozSize(){
    return this->canaisVoz.size();
}

/**
 * @brief Função que retorna a quantidade de canais de texto de um servidor
 * 
 * @return int
 */
int Servidor::getCanaisTextoSize(){
    return this->canaisTexto.size();
}



/**
 * @brief Função que define o id do dono do servidor
 * 
 * @param usuarioDonoId 
 */
void Servidor::setDonoID(int usuarioDonoId){
    this->usuarioDonoId = usuarioDonoId;
}

/**
 * @brief Função que define o nome de um servidor
 * 
 * @param nome 
 */
void Servidor::setNome(std::string nome){
    this->nome = nome;
}

/**
 * @brief Função que define a descrição de um servidor
 * 
 * @param descricao 
 */
void Servidor::setDescricao(std::string descricao){
    this->descricao = descricao;
}

/**
 * @brief Função que define o código de convite de um servidor
 * 
 * @param codigoConvite 
 */
void Servidor::setCodigoConvite(std::string codigoConvite){
    this->codigoConvite = codigoConvite;
}

/**
 * @brief Função que define os canais de um servidor
 * 
 * @param canais 
 */
void Servidor::setCanais(std::vector<Canal> canais){
    this->canais = canais;
}

/**
 * @brief Função que define os canais de voz de um servidor
 * 
 * @param canaisVoz 
 */
void Servidor::setCanaisVoz(std::vector<CanalVoz> canaisVoz){
    this->canaisVoz = canaisVoz;
}

/**
 * @brief Função que define os canais de texto de um servidor
 * 
 * @param canaisTexto 
 */
void Servidor::setCanaisTexto(std::vector<CanalTexto> canaisTexto){
    this->canaisTexto = canaisTexto;
}

/**
 * @brief Função que define os ids dos participantes de um servidor
 * 
 * @param participantesIDs 
 */
void Servidor::setParticipantesIDs(std::vector<int> participantesIDs){
    this->participantesIDs = participantesIDs;

}

/**
 * @brief Função que adiciona o id de um participante na lista de participantes do servidor
 * 
 * @param participanteID 
 */
void Servidor::addParticipantesIDs(int participanteID){
    this->participantesIDs.push_back(participanteID);
}

/**
 * @brief Função que adiciona um canal de texto na lista de canais do servidor
 * 
 * @param canal 
 */
void Servidor::addCanalTexto(CanalTexto canal){
    this->canais.push_back(canal);
    this->canaisTexto.push_back(canal);
}

/**
 * @brief Função que adiciona um canal de voz na lista de canais do servidor
 * 
 * @param canal 
 */
void Servidor::addCanalVoz(CanalVoz canal){
    this->canais.push_back(canal);
    this->canaisVoz.push_back(canal);
}

/**
 * @brief Função que adiciona mensagens a um canal de vozdo servidor
 * 
 * @param mensagem
 */
void Servidor::addMensagens_v(Mensagem mensagem, std::string atual){
    for(int i = 0; i < getCanaisVozSize(); i++){
        if(this->canaisVoz[i].getNome() == atual){
            this->canaisVoz[i].setUltimaMensagem(mensagem);
        }
    }
}

/**
 * @brief Função que adiciona mensagens a um canal de texto do servidor
 * 
 * @param mensagem
 */
void Servidor::addMensagens_t(Mensagem mensagem, std::string atual){
    for(int i = 0; i < getCanaisTextoSize(); i++){
        if(this->canaisTexto[i].getNome() == atual){
            this->canaisTexto[i].addMensagem(mensagem);
        }
    }
}