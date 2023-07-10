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

Essas são as possibilidades de entrada para o programa, de maneira a serem testadas as suas diversas funcionalidades da parte 1:

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
A seguir estão as possibilidades do programa para testar as funcionalidades da parte 2:

Note que quando a mensagem é mostrada, a parte de data e hora está de maneira generalizada no formato "<dia/mês/ano - horas:minutos:segundos>", mas quando o programa estiver rodando, seram impressas as informações características do momento em que o programa está sendo executado.

```
create-user raquel@gmail senha123 raquel freire
>Usuário criado com sucesso!
create-user marc@gmail senha1234 Marcos B
>Usuário criado com sucesso!
login raquel@gmail senha123
>Logado como raquel@gmail!
create-server deus
>Servidor criado com sucesso!
create-channel jogos voz
>Canal de voz criado com sucesso!
create-channel cafezinho texto
>Canal de texto criado com sucesso!
list-channels
>#canais de texto
>cafezinho
>#canais de voz
>jogos
enter-channel jogos
>Entrou no canal com sucesso!
list-messages
>Não há mensagens!
send-message vamo jogar agora ou mais tarde??
>Mensagem enviada com sucesso!
list-messages
>raquel freire<dia/mês/ano - horas:minutos:segundos>: vamo jogar agora ou mais tarde??
leave-channel
>Saindo do canal...
enter-channel cafezinho
>Entrou no canal com sucesso!
send-message caramba, boy
>Mensagem enviada com sucesso!
send-message que ódio desse cara
>Mensagem enviada com sucesso!
send-message amei as fofocas de hoje
>Mensagem enviada com sucesso!
list-messages
>raquel freire<dia/mês/ano - horas:minutos:segundos>: caramba, boy
>raquel freire<dia/mês/ano - horas:minutos:segundos>: que ódio desse cara
>raquel freire<dia/mês/ano - horas:minutos:segundos>: amei as fofocas de hoje
leave-channel
>Saindo do Canal...
disconnect
>Desconectado com sucesso!
login marc@gmail senha1234
>Logado como marc@gmail!
enter-server deus
>Entrou no servidor com sucesso!
enter-channel cafezinho
>Entrou no canal com sucesso!
list-messages
>raquel freire<dia/mês/ano - horas:minutos:segundos>: caramba, boy
>raquel freire<dia/mês/ano - horas:minutos:segundos>: que ódio desse cara
>raquel freire<dia/mês/ano - horas:minutos:segundos>: amei as fofocas de hoje
send-message também adoreeei
>Mensagem enviada com sucesso!
list-messages
>raquel freire<dia/mês/ano - horas:minutos:segundos>: caramba, boy
>raquel freire<dia/mês/ano - horas:minutos:segundos>: que ódio desse cara
>raquel freire<dia/mês/ano - horas:minutos:segundos>: amei as fofocas de hoje
>Marcos B<dia/mês/ano - horas:minutos:segundos>: também adoreeei
leave-channel
>Saindo do Canal...
disconnect
>Desconectado com sucesso!
quit
>Saindo do Concordo...
```

A seguir estão as possibilidades do programa para testar as funcionalidades da parte 3:

```
create-user raquel@gmail senha123 raquel freire
>Usuário criado com sucesso!
create-user marc@gmail senha1234 Marcos B
>Usuário criado com sucesso!
login raquel@gmail senha123
>Logado como raquel@gmail!
create-server spa
>Servidor criado com sucesso!
create-server deus
>Servidor criado com sucesso!
set-server-desc deus amem
>Descrição adicionada com sucesso!
set-server-invite-code deus bora
>Código de convite adicionado com sucesso!
set-server-desc spa vamo??
>Descrição adicionada com sucesso!
create-channel jogos voz
>Canal de voz criado com sucesso!
create-channel cafezinho texto
>Canal de texto criado com sucesso!
enter-channel jogos
>Entrou no canal com sucesso!
send-message vamo jogar agora ou mais tarde??
>Mensagem enviada com sucesso!
leave-channel
>Saindo do canal...
enter-channel cafezinho
>Entrou no canal com sucesso!
send-message caramba, boy
>Mensagem enviada com sucesso!
send-message que ódio desse cara
>Mensagem enviada com sucesso!
send-message amei as fofocas de hoje
>Mensagem enviada com sucesso!
leave-channel
>Saindo do Canal...
disconnect
>Desconectado com sucesso!
quit
>Saindo do Concordo...

./Concordo

login marc@gmail senha1234
>Logado como marc@gmail!
list-servers
>spa
>deus
enter-server deus bora
>Entrou no servidor com sucesso!
enter-channel cafezinho
>Entrou no canal com sucesso!
list-messages
>raquel freire<dia/mês/ano - horas:minutos:segundos>: caramba, boy
>raquel freire<dia/mês/ano - horas:minutos:segundos>: que ódio desse cara
>raquel freire<dia/mês/ano - horas:minutos:segundos>: amei as fofocas de hoje
send-message também adoreeei
>Mensagem enviada com sucesso!
list-messages
>raquel freire<dia/mês/ano - horas:minutos:segundos>: caramba, boy
>raquel freire<dia/mês/ano - horas:minutos:segundos>: que ódio desse cara
>raquel freire<dia/mês/ano - horas:minutos:segundos>: amei as fofocas de hoje
>Marcos B<dia/mês/ano - horas:minutos:segundos>: também adoreeei
leave-channel
>Saindo do Canal...
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