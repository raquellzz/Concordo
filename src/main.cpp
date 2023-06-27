#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sistema.h"
#include "Executor.h"

int main(){
    
    Sistema sistema;
    Executor executor(&sistema);
    executor.iniciar();
    return 0;
}