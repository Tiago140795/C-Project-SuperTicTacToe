//
// Created by Tiago Meireles on 28/05/2022.
//

#ifndef TRABALHO_HISTORICO_H
#define TRABALHO_HISTORICO_H
#include "stdio.h"
#include <stdlib.h>

typedef struct historico hist, *phist;
struct historico{
    phist prox;
    int player,num,x,y,a,b;
};

int checkHist(phist h); //verifica se o historico esta vazio
void printHist(phist h); //percorre a lista ligada e mostra o conteudo de cada um
void printRecentHist(phist h, int num); //mostra o conteudo de o valor a ate ao fim da lista ligada
phist insertHist(phist h, int num, int player, int x, int y, int a, int b); //insere um novo elemento
phist deleteHist(phist h); //elimina o elemento do fim
void newHist(phist new, int num, int player, int x, int y, int a, int b); //cria um novo elemento

#endif //TRABALHO_HISTORICO_H
