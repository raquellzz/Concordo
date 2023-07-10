/**
 * @file Sistema.cpp
 * 
 * @brief Implementação dos métodos da classe Sistema.
 * 
 */

#include "Sistema.h"
#include <iostream>
#include "Usuario.h"
#include <vector>
#include <time.h>
#include <fstream>


/**
 * @brief Função para aumentar o último id
 * 
 */
void Sistema::increaseId(){
    id++;
}

/**
 * @brief Função que retorna o último id
 * 
 * @return int 
 */
int Sistema::getId(){
    return id;
}

/**
 * @brief Função que define o último id do sistema
 * 
 */
void Sistema::setId(int id){
    this->id = id;
}

/**
 * @brief Função que retorna a quantidade de usuários cadastrados
 * 
 * @return int 
 */
int Sistema::getusuarios(){
    return usuarios.size();
}

/**
 * @brief Função que retorna a quantidade de servidores criados
 * 
 * @return int 
 */
int Sistema::getServidores(){
    return servidores.size();
}



/**
 * @brief Função que retorna o nome do usuário
 * 
 * @return string
 */
std::string Sistema::getUsuario(int idUsuario){
    for(int i = 0; i < getusuarios(); i++){
        if(usuarios[i].getId() == idUsuario){
            return usuarios[i].getNome();
        }
    }
    return "";
}

/**
 * @brief Função que salva os dados dos usuários em um arquivo
 * 
 */
void Sistema::salvarUsuarios(){
    std::ofstream arquivo;
    arquivo.open("usuarios.txt");
    arquivo << getusuarios() << "\n";
    for(int i = 0; i < getusuarios(); i++){
        arquivo << usuarios[i].getId() << "\n";
        arquivo << usuarios[i].getEmail() << "\n";
        arquivo << usuarios[i].getSenha() << "\n";
        arquivo << usuarios[i].getNome() << "\n";
    }
    arquivo.close();
}

/**
 * @brief Função que salva os dados dos servidores em um arquivo
 * 
 */
void Sistema::salvarServidores(){
    std::ofstream arquivo;
    arquivo.open("servidores.txt");
    arquivo << getServidores() << "\n";
    for(int i = 0; i < getServidores(); i++){
        arquivo << servidores[i].getDonoID() << "\n";
        arquivo << servidores[i].getNome() << "\n";
        arquivo << servidores[i].getDescricao() << "\n";
        arquivo << servidores[i].getCodigoConvite() << "\n";
        arquivo << servidores[i].getparticpantes() << "\n";
        for(int j = 0; j < servidores[i].getparticpantes(); j++){
            arquivo << servidores[i].getParticipantesIDs()[j] << "\n";
        }
        arquivo << servidores[i].getCanaisSize() << "\n";
        for(int j = 0; j < servidores[i].getCanaisTextoSize(); j++){
            arquivo << servidores[i].getCanaisTexto()[j].getNome() << "\n";
            arquivo << servidores[i].getCanaisTexto()[j].getTipo() << "\n";
            arquivo << servidores[i].getCanaisTexto()[j].getMensagensSize() << "\n";
            for(int k = 0; k < servidores[i].getCanaisTexto()[j].getMensagensSize(); k++){
                arquivo << servidores[i].getCanaisTexto()[j].getMensagens()[k].getEnviadaPor() << "\n";
                arquivo << servidores[i].getCanaisTexto()[j].getMensagens()[k].getDataHora() << "\n";
                arquivo << servidores[i].getCanaisTexto()[j].getMensagens()[k].getConteudo() << "\n";
            }
        }
        for(int j = 0; j < servidores[i].getCanaisVozSize(); j++){
            arquivo << servidores[i].getCanaisVoz()[j].getNome() << "\n";
            arquivo << servidores[i].getCanaisVoz()[j].getTipo() << "\n";
            arquivo << 1 << "\n";
            arquivo << servidores[i].getCanaisVoz()[j].getUltimaMensagem().getEnviadaPor() << "\n";
            arquivo << servidores[i].getCanaisVoz()[j].getUltimaMensagem().getDataHora() << "\n";
            arquivo << servidores[i].getCanaisVoz()[j].getUltimaMensagem().getConteudo() << "\n";
        }
    }
    arquivo.close();
}

/**
 * @brief Função que carrega os dados dos usuários de um arquivo
 * 
 */
void Sistema::carregarUsuarios(){
    std::ifstream arquivo;
    arquivo.open("usuarios.txt");
    int usuariosSize;
    arquivo >> usuariosSize;
    if(usuariosSize == 0){
        arquivo.close();
        return;
    }
    int id;
    std::string nome, email, senha;
    while(arquivo >> id){
        arquivo.ignore();
        std::getline(arquivo, email);
        std::getline(arquivo, senha);
        std::getline(arquivo, nome);
        Usuario usuario(id, email, senha, nome);
        usuarios.push_back(usuario);
    }
    arquivo.close();
}

/**
 * @brief Função que carrega os dados dos servidores de um arquivo
 * 
 */
void Sistema::carregarServidores(){
    std::ifstream arquivo;
    arquivo.open("servidores.txt");
    int servidoresSize;
    arquivo >> servidoresSize;
    if(servidoresSize == 0){
        arquivo.close();
        return;
    }
    int donoID, particpantes, canaisSize, mensagensSize;
    std::string nome, descricao, codigoConvite, nomeCanal, tipoCanal, conteudo, dataHora;
    while(arquivo >> donoID){
        arquivo.ignore();
        std::getline(arquivo, nome);
        std::getline(arquivo, descricao);
        std::getline(arquivo, codigoConvite);
        arquivo >> particpantes;
        arquivo.ignore();
        std::vector<int> participantesIDs;
        for(int i = 0; i < particpantes; i++){
            int id;
            arquivo >> id;
            participantesIDs.push_back(id);
        }
        arquivo >> canaisSize;
        arquivo.ignore();
        std::vector<CanalTexto> canaisTexto;
        std::vector<CanalVoz> canaisVoz;
        for(int i = 0; i < canaisSize; i++){
            std::getline(arquivo, nomeCanal);
            std::getline(arquivo, tipoCanal);
            if(tipoCanal == "texto"){
                arquivo >> mensagensSize;
                arquivo.ignore();
                std::vector<Mensagem> mensagens;
                for(int j = 0; j < mensagensSize; j++){
                    int enviadaPor;
                    std::getline(arquivo, dataHora);
                    std::getline(arquivo, conteudo);
                    arquivo >> enviadaPor;
                    arquivo.ignore();
                    Mensagem novaMensagem(enviadaPor, dataHora, conteudo);
                    mensagens.push_back(novaMensagem);
                }
                CanalTexto novoCanal(nomeCanal);
                novoCanal.setMensagens(mensagens);
                
                canaisTexto.push_back(novoCanal);
            }
            else{
                std::getline(arquivo, dataHora);
                std::getline(arquivo, conteudo);
                Mensagem ultimaMensagem(0, dataHora, conteudo);
                CanalVoz novoCanal(nomeCanal);
                novoCanal.setUltimaMensagem(ultimaMensagem);
                canaisVoz.push_back(novoCanal);
            }
        }
        Servidor novoServidor(donoID, nome, descricao, codigoConvite);
        novoServidor.setCanaisTexto(canaisTexto);
        novoServidor.setCanaisVoz(canaisVoz);
        novoServidor.setParticipantesIDs(participantesIDs);
        servidores.push_back(novoServidor);
    }
    arquivo.close();
}

/**
 * @brief Função que salva os dados do sistema em arquivos
 * 
 */
void Sistema::salvar(){
    salvarUsuarios();
    salvarServidores();
}

/**
 * @brief Função que carrega os dados do sistema de arquivos
 * 
 */
void Sistema::carregar(){
    carregarUsuarios();
    carregarServidores();
}

/**
 * @brief Função que verifica se há um usuário logado
 * 
 * @param usuarioLogadoId 
 * @return std::string 
 */
std::string Sistema::verify_login(int usuarioLogadoId){
    if (usuarioLogadoId == -1){
        return "Nenhum usuário logado!";
    }
    return "";
}

/**
 * @brief Função que representa o comando para sair do sistema
 * 
 * @return std::string 
 */
std::string Sistema::quit(){
    return "Saindo do Concordo...";
}

/**
 * @brief Função que representa o comando para criar usuário
 * 
 * @param email 
 * @param senha 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::create_user (const std::string email, const std::string senha, const std::string nome){
    verify_login(usuarioLogadoId);
    if(email == "" || senha == "" || nome == ""){
        return "Dados inválidos.";
    }
    for(int i = 0; i < getusuarios(); i++){
        if(usuarios[i].getEmail() == email){
            return "Usuário já existe.";
        }
    }
    if(getusuarios() == 0){
        setId(0);
    }
    increaseId();
    Usuario novoUsuario(getId(), email, senha, nome);
    usuarios.push_back(novoUsuario);
    salvar();
    return "Usuário criado com sucesso!";
}

/**
 * @brief Função que representa o comando para fazer login no sistema
 * 
 * @param email 
 * @param senha 
 * @return std::string 
 */
std::string Sistema::login (std::string email, std::string senha){
    if(usuarioLogadoId != -1){
        return "Usuário já está logado!";
    }
    for (int i = 0; i < getusuarios(); i++){
        if (usuarios[i].getEmail() == email){
            if (usuarios[i].getSenha() == senha){
                usuarioLogadoId = usuarios[i].getId();
                return "Logado como " + usuarios[i].getEmail() + "!";
            }
            else{
                return "Senha incorreta!";
            }
        }
    }
    return "Usuário não encontrado!";
}

/**
 * @brief Função que representa o comando para desconectar o usuário do sistema
 * 
 * @return std::string 
 */
std::string Sistema::disconnect(){
    usuarioLogadoId = -1;
    return "Desconectado com sucesso!";
}

/**
 * @brief Função que representa o comando para criar um servidor
 * 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::create_server (std::string nome){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            return "Servidor já existe!";
        }
    }
    Servidor novoServidor(usuarioLogadoId, nome, "", "");
    
    servidores.push_back(novoServidor);
    servidores[getServidores()-1].addParticipantesIDs(usuarioLogadoId);
    servidorAtual = novoServidor.getNome();
    salvar();
    return "Servidor criado com sucesso!";
}

/**
 * @brief Função que representa o comando para definir a descrição de um servidor
 * 
 * @param nome 
 * @param descricao 
 * @return std::string 
 */
std::string Sistema::set_server_desc(std::string nome, std::string descricao){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if(servidores[i].getDonoID() != usuarioLogadoId){
                return "Você não é o dono do servidor!";
            }
            servidores[i].setDescricao(descricao);
            salvar();
            return "Descrição adicionada com sucesso!";
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para definir o código de convite de um servidor
 * 
 * @param nome 
 * @param codigo 
 * @return std::string 
 */
std::string Sistema::set_server_invite_code(std::string nome, std::string codigo){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if(servidores[i].getDonoID() != usuarioLogadoId){
                return "Você não é o dono do servidor!";
            }
            servidores[i].setCodigoConvite(codigo);
            salvar();  
            return "Código de convite adicionado com sucesso!";
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para listar os servidores existentes no sistema
 * 
 * @return std::string 
 */
std::string Sistema::list_servers(){
    verify_login(usuarioLogadoId);
    std::string lista = "";
    for (int i = 0; i < getServidores(); i++){
        if(i == getServidores()-1){
            lista += servidores[i].getNome();
            return lista;
        }
        lista += servidores[i].getNome() + "\n";
    }
    return lista;
}

/**
 * @brief Função que representa o comando para remover um servidor do sistema
 * 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::remove_server(std::string nome){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if (servidores[i].getDonoID() == usuarioLogadoId){
                servidores.erase(servidores.begin() + i);
                servidorAtual = "";
                salvar();
                return "Servidor removido com sucesso!";
            }
            else{
                return "Você não é o dono do servidor!";
            }
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para entrar em um servidor existente
 * 
 * @param nome 
 * @param codigo 
 * @return std::string 
 */
std::string Sistema::enter_server(std::string nome, std::string codigo){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == nome){
            if (servidores[i].getCodigoConvite() == codigo){
                servidorAtual = nome;
                servidores[i].addParticipantesIDs(usuarioLogadoId);
                salvar();
                return "Entrou no servidor com sucesso!";
            }
            else{
                return "Código de convite inválido!";
            }
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para deslogar de um servidor
 * 
 * @return std::string 
 */
std::string Sistema::leave_server(){
    verify_login(usuarioLogadoId);
    servidorAtual = "";
    return "Saindo do servidor...";
}

/**
 * @brief Função que representa o comando para listar os participantes do servidor atual
 * 
 * @return std::string 
 */
std::string Sistema::list_participants(){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == servidorAtual){
            std::string lista = "";
            for (int j = 0; j < servidores[i].getparticpantes(); j++){
                for(int k = 0; k < getusuarios(); k++){
                    if(usuarios[k].getId() == servidores[i].getParticipantesIDs()[j]){
                        if(k == getusuarios() - 1){
                            lista += usuarios[k].getNome();
                            break;
                        }
                        lista += usuarios[k].getNome() + "\n";
                    }
                    
                }
            }
            if(lista != "")
                return lista;
            return "Não há participantes no servidor!";
        }
    }
    return "Servidor não encontrado!";
}

/**
 * @brief Função que representa o comando para listar os canais do servidor atual
 * 
 * @return std::string 
 */
std::string Sistema::list_channels(){
    verify_login(usuarioLogadoId);
    for (int i = 0; i < getServidores(); i++){
        if (servidores[i].getNome() == servidorAtual){
            std::string lista = "#canais de texto\n";
            for(int j = 0; j < servidores[i].getCanaisTextoSize(); j++){
                lista += servidores[i].getCanaisTexto()[j].getNome() + "\n";
            }
            lista += "#canais de voz\n";
            for(int j = 0; j < servidores[i].getCanaisVozSize(); j++){
                if(j == servidores[i].getCanaisVozSize() - 1){
                    lista += servidores[i].getCanaisVoz()[j].getNome();
                    break;
                }
                lista += servidores[i].getCanaisVoz()[j].getNome() + "\n";
            }
            return lista;
        }
    }
    return "Você não está em um servidor!";
}

/**
 * @brief Função que representa o comando para criar um canal no servidor atual
 * 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::create_channel(std::string nome, std::string tipo){
    verify_login(usuarioLogadoId);
    for(int i = 0; i < getServidores(); i++){
        if(servidores[i].getNome() == servidorAtual){
            if(servidores[i].getDonoID() != usuarioLogadoId){
                return "Você não é o dono do servidor!";
            }
            if(tipo == "texto"){
                CanalTexto canal(nome);
                servidores[i].addCanalTexto(canal);
                salvar();
                return "Canal de texto criado com sucesso!";
            }
            else if(tipo == "voz"){
                CanalVoz canal(nome);
                servidores[i].addCanalVoz(canal);
                salvar();
                return "Canal de voz criado com sucesso!";
            }
            else{
                return "Tipo de canal inválido!";
            }
        }
    }
    return "Você não está em um servidor!";
}

/**
 * @brief Função que representa o comando para entrar em um canal do servidor atual
 * 
 * @param nome 
 * @return std::string 
 */
std::string Sistema::enter_channel(std::string nome){
    verify_login(usuarioLogadoId);
    for(int i = 0; i < getServidores(); i++){
        if(servidores[i].getNome() == servidorAtual){
            for(int j = 0; j < servidores[i].getCanaisSize(); j++){
                if(servidores[i].getCanais()[j].getNome() == nome){
                    canalAtual = nome;
                    return "Entrou no canal com sucesso!";
                }
            }
            return "Canal não encontrado!";
        }
    }
    return "Você não está em um servidor!";
}

/**
 * @brief Função que representa o comando para sair de um canal do servidor atual
 * 
 * @return std::string 
 */
std::string Sistema::leave_channel(){
    verify_login(usuarioLogadoId);
    if(servidorAtual == ""){
        return "Você não está em um servidor!";
    }
    if(canalAtual != ""){
        canalAtual = "";
        return "Saindo do canal...";
    }
    return "Você não está em um canal!";
    
}

/**
 * @brief Função que representa o comando para enviar uma mensagem no canal atual
 * 
 * @param mensagem 
 * @return std::string 
 */
std::string Sistema::send_message(std::string mensagem){
    verify_login(usuarioLogadoId);
    if(servidorAtual == ""){
        return "Você não está em um servidor!";
    }
    if(canalAtual == ""){
        return "Você não está em um canal!";
    }
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    std::string datahora = "<" + std::to_string(data_hora_atual->tm_mday) + "/" + std::to_string(data_hora_atual->tm_mon + 1) + "/" + std::to_string(data_hora_atual->tm_year + 1900) + " - " + std::to_string(data_hora_atual->tm_hour) + ":" + std::to_string(data_hora_atual->tm_min) + ":" + std::to_string(data_hora_atual->tm_sec) + ">";
    Mensagem msg(usuarioLogadoId, datahora, mensagem);

    for(int i = 0; i < getServidores(); i++){
        if(servidores[i].getNome() == servidorAtual){
            for(int j = 0; j < servidores[i].getCanaisSize(); j++){
                if(servidores[i].getCanaisVoz()[j].getNome() == canalAtual){
                    servidores[i].addMensagens_v(msg, canalAtual);
                    
                    salvar();
                    return "Mensagem enviada com sucesso!";
                }
                if(servidores[i].getCanaisTexto()[j].getNome() == canalAtual){
                    servidores[i].addMensagens_t(msg, canalAtual);
                    
                    salvar();
                    return "Mensagem enviada com sucesso!";
                }
            }
        }
    }
    return "";
}

/**
 * @brief Função que representa o comando para listar as mensagens do canal atual
 * 
 * @return std::string 
 */
std::string Sistema::list_messages(){
    verify_login(usuarioLogadoId);
    if(servidorAtual == ""){
        return "Você não está em um servidor!";
    }
    if(canalAtual == ""){
        return "Você não está em um canal!";
    }
    
    for(int i = 0; i < getServidores(); i++){
        if(servidores[i].getNome() == servidorAtual){
            for(int j = 0; j < servidores[i].getCanaisSize(); j++){
                if(servidores[i].getCanaisVoz()[j].getNome() == canalAtual){
                    std::string ultmensagem = "";
                    ultmensagem += getUsuario(servidores[i].getCanaisVoz()[j].getUltimaMensagem().getEnviadaPor()) + servidores[i].getCanaisVoz()[j].getUltimaMensagem().getDataHora() + ": " + servidores[i].getCanaisVoz()[j].getUltimaMensagem().getConteudo();
                    if(ultmensagem == ": " || ultmensagem == ""){
                        return "Não há mensagens!";
                    }
                    return ultmensagem;
                }
                if(servidores[i].getCanaisTexto()[j].getNome() == canalAtual){
                    std::string lista = "";
                    for(int k = 0; k < servidores[i].getCanaisTexto()[j].getMensagensSize(); k++){
                        if(k == servidores[i].getCanaisTexto()[j].getMensagensSize() - 1){
                            lista += getUsuario(servidores[i].getCanaisTexto()[j].getMensagens()[k].getEnviadaPor()) + servidores[i].getCanaisTexto()[j].getMensagens()[k].getDataHora() + ": " + servidores[i].getCanaisTexto()[j].getMensagens()[k].getConteudo();
                            break;
                        }
                        lista += getUsuario(servidores[i].getCanaisTexto()[j].getMensagens()[k].getEnviadaPor()) + servidores[i].getCanaisTexto()[j].getMensagens()[k].getDataHora() + ": " + servidores[i].getCanaisTexto()[j].getMensagens()[k].getConteudo() + "\n";
                    }
                    if(lista == ": " || lista == ""){
                        return "Não há mensagens!";
                    }  
                    return lista;
                }
            }
        }
    }
    return "";
}