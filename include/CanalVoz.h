/**
 * @file CanalVoz.h
 * 
 * @brief Definição da classe CanalVoz.
 * 
 */

#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <string>
#include <iostream>
#include <vector>
#include "Mensagem.h"
#include "Canal.h"

/**
 * @brief Classe que representa um canal de voz de um servidor.
 * 
 */
class CanalVoz : public Canal{
    Mensagem ultimaMensagem; //!< Mensagem que aramazena todos os atributos da última mensagem enviada no canal de voz
};

#endif