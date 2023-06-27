/**
 * @file Canal.h
 * 
 * @brief Definição da classe Canal.
 * 
 */

#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <iostream>

/**
 * @brief Classe que representa um canal de um servidor
 * 
 */
class Canal{
    public:
    std::string nome; //!< Armazena o nome do canal

    //specials
    Canal();
    Canal(std::string nome);

    //gets
    std::string getNome();

    //sets
    void setNome(std::string nome);
};

#endif