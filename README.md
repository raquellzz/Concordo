<h1 align="center"> Projeto 3: Concordo </h1>

# Índice 

* [Índice](#índice)
* [Descrição do Projeto](#descrição-do-projeto)
* [Roteiro de Entradas e Saídas](#roteiro-de-entradas-e-saídas)
* [Acesso ao Projeto e Compilação](#acesso-ao-projeto-e-compilação)
* [Pessoas Desenvolvedoras do Projeto](#pessoas-desenvolvedoras-do-projeto)

# Descrição do Projeto

O intuito deste projeto é aplicar o conhecimento adquirido na linguagem de programação C++ no desenvolvimento de um sistema de comunidades, denominado Concordo, com recursos similares ao Discord.

# Roteiro de Entradas e Saídas

O sistema pode receber os seguintes comandos:

```
quit

create-user <email> <senha_sem_espaços> <nome com espaços>

login <email> <senha>

disconnect

create-server <nome>

set-server-desc <nome> <descrição>

set-server-invite-code <nome> <código>

list-servers 

remove-server <nome>

enter-server <nome> <código>

list-participants

```

Essas são as possibilidades de entrada para o programa, de maneira a serem testadas as suas diversas funcionalidades:

Lembre que senhas e emails não podem conter espaço, bem como nome de servidores e canais. Nome de usuário pode ter espaço.

Note que outputs estão caracterizados a seguir com o símbolo ">" apenas para facilitar a compreensão das entradas e saídas, no terminal não possui esse símbolo antes de cada saída.
```
create-user marc@gmail senha1234 
>Dados inválidos.
create-user raquel@gmail senha123 raquel freire
>Usuário criado com sucesso!
create-user marc@gmail senha1234 Marcos B
>Usuário criado com sucesso!
login raquel@gmail senhaErrada
>Senha incorreta!
login raquel@gmail senha123
>Logado como raquel@gmail!
create-server deus
>Servidor criado com sucesso!
create-server spa
>Servidor criado com sucesso!
set-server-desc deus amem
>Descrição adicionada com sucesso!
set-server-invite-code deus bora
>Código de convite adicionado com sucesso!
disconnect
>Desconectado com sucesso!
login marc@gmail senha1234
>Logado como marc@gmail!
list-servers
>deus
>spa
enter-server deus
>Código de convite inválido!
enter-server deus bora
>Entrou no servidor com sucesso!
list-participants
>raquel freire
>Marcos B
remove-server deus
>Você não é o dono do servidor!
leave-server
>Saindo do servidor...
disconnect
>Desconectado com sucesso!
login raquel@gmail senha123
>Logado como raquel@gmail!
remove-server deus
>Servidor removido com sucesso!
list-servers
>spa
disconnect
>Desconectado com sucesso!
quit
>Saindo do Concordo...
```


# Acesso ao Projeto e Compilação

É possível acessar o repositório do projeto no Github ou baixá-lo.

Para compilação foi utilizado o Cmake na versão 3.22.1, para testar o programa é necessário ter o Cmake instalado.

Dentro da pasta do projeto, para criar e entrar na pasta build, digite o comando 
```
mkdir build
cd build
```
Em seguida
```
cmake ..
make
```
E para executar o programa
```
./Concordo
```


# Pessoas Desenvolvedoras do Projeto

Esse projeto foi desenvolvido pela aluna Raquel da Costa Freire, discente curso de graduação Tecnologia da Informação na UFRN no semestre 2023.1, por meio da disciplina Linguagem de Programação 1.