#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <iostream>
#include <vector>
#include "Mensagem.h"
#include "Canal.h"

class CanalTexto : public Canal {
    std::vector<Mensagem> mensagens;
    public:
        CanalTexto();
        CanalTexto(std::string nome);
        ~CanalTexto();

        std::vector<Mensagem> getMensagens();
        void setMensagens(std::vector<Mensagem> mensagens);
};

#endif
