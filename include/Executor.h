#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include <iostream>
#include <vector>
#include "Sistema.h"
#include <fstream>


class Executor{
private:
    Sistema *sistema;
    
    bool sair = false;

public:
    Executor(Sistema *sistema);

    void iniciar();

    std::string LeituraComandos(std::string linha, Sistema *sistema);
};

#endif