#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include <iostream>
#include <vector>
#include "Sistema.h"


class Executor{
private:
    Sistema *sistema;

public:
    Executor(Sistema *sistema);

    void iniciar();

    std::string LeituraComandos(std::string linha, Sistema *sistema);
};

#endif