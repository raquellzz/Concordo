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
    std::vector<Mensagem> mensagens; //!< Armazena todas as mensagens enviadas no canal de texto
    public:
        CanalTexto();
        CanalTexto(std::string nome);

        std::vector<Mensagem> getMensagens();
        void setMensagens(std::vector<Mensagem> mensagens);
};

#endif
