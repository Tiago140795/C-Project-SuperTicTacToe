//
// Created by Tiago Meireles on 24/05/2022.
//

#ifndef TRABALHO_TIC_H
#define TRABALHO_TIC_H
#include "stdio.h"
#include <stdlib.h>

struct matriztic{
    char **p; // ponteiro para a matriz dinamica
};
typedef struct matriztic tic;

void printTic(char **p, int nLin, int nCol); //imprime a matriz apontada pelo ponteiro
int verifyTic(char **p); //verica se o tic ja esta tem os requeritos para estar ganho ou nao(3x3)
int verifyAvailableSpaces(char **p); //verifica se o tic tem espacos disponiveis

#endif //TRABALHO_TIC_H
