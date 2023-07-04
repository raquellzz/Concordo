/**
 * @file CanalTexto.h
 * 
 * @brief Definição da classe CanalTexto.
 * 
 */

#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <iostream>
#include <vector>
#include "Mensagem.h"
#include "Canal.h"

/**
 * @brief Classe que representa um canal de texto de um servidor
 * 
 */
class CanalTexto : public Canal {
    public:
    std::vector<Mensagem> mensagens; //!< Armazena todas as mensagens enviadas no canal de texto
    
        CanalTexto(std::string nome);

        std::string getTipo();
        int getMensagensSize();

        std::vector<Mensagem> getMensagens();
        void setMensagens(std::vector<Mensagem> mensagens);
        void addMensagem(Mensagem mensagem);
};

#endif
