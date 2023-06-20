#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <iostream>

class Canal{
    public:
    std::string nome;

    //specials
    Canal();
    Canal(std::string nome);
    ~Canal();

    //gets
    std::string getNome();

    //sets
    void setNome(std::string nome);
};

#endif