cmake_minimum_required(VERSION 3.20)
project(Trabalho C)

set(CMAKE_C_STANDARD 99)

add_executable(Projeto main.c tic.h tic.c supertic.h supertic.c matdin.h  matdin.c jogo.h jogo.c utils.h utils.c historico.c historico.h)
