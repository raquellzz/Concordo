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

Essas são as possibildiades de entrada para o programa, de maneira a serem testadas as suas diversas funcionalidades:

Lembre que senhas e emails não podem conter espaço, bem como nome de servidores e canais. Nome de usuário pode ter espaço.

Os outputs estão caracterizados a seguir com o símbolo >
```
create-user marc@gmail senha1234 
>
create-user raquel@gmail senha123 raquel freire
>
create-user marc@gmail senha1234 Marcos B
>
login raquel@gmail senhaErrada
>
login raquel@gmail senha123
>
create-server deus
>
set-server-desc deus amem
>
set-server-invite-code deus bora
>
disconnect
>
login marc@gmail senha1234
>
quit
>
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