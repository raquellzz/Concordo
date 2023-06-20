#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <string>
#include <iostream>
#include <vector>
#include "Mensagem.h"
#include "Canal.h"

class CanalVoz : public Canal{
    Mensagem ultimaMensagem;

};

#endif