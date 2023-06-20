#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <iostream>
#include <vector>
#include "Mensagem.h"
#include "Canal.h"

class CanalTexto : public Canal {
    std::vector<Mensagem> mensagens;

};

#endif
