cmake_minimum_required(VERSION 3.22.1)
project(teste VERSION 0.1 LANGUAGES CXX )

set( CMAKE_CXX_FLAGS "-Wall")

include_directories( include )


add_executable( Concordo
                src/Concordo.cpp
                src/Usuario.cpp
                src/Sistema.cpp
                src/Servidor.cpp
                src/Mensagem.cpp
                src/Executor.cpp
                src/CanalVoz.cpp
                src/CanalTexto.cpp
                src/Canal.cpp)

set_property(TARGET Concordo PROPERTY CXX_STANDARD 14)