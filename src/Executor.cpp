#include <string>
#include <iostream>
#include <vector>
#include "Executor.h"

void Executor::iniciar(){
    std::string linha;
    std::getline(std::cin, linha);
    std::cout << LeituraComandos(linha, sistema) << std::endl;
}


std::string Executor::LeituraComandos(std::string linha, Sistema *sistema){
    std::string comando;
    for(auto c: linha){
        if(c == ' '){
            break;
        }
        comando += c;
    }
    if(comando == "quit"){
        return sistema->quit();
    }
    else if(comando == "create_user"){

    }
    else if(comando == "login"){

    }
    else if(comando == "disconnect"){
        return sistema->disconnect();
    }
    else if(comando == "create_server"){
        
    }
    else if(comando == "set_server_desc"){
        
    }
    else if(comando == "set_server_invite_code"){
        
    }
    else if(comando == "list_servers"){
        return sistema->list_servers();
    }
}