//
// Created by Tiago Meireles on 24/05/2022.
//

#ifndef TRABALHO_SUPERTIC_H
#define TRABALHO_SUPERTIC_H

#include <stdlib.h>
#include <stdio.h>
#include "tic.h"
#include "matdin.h"
#include "utils.h"
#include "historico.h"
#include "string.h"

struct matrizsuper{
    phist hist; //ponteiro para inicio da lista ligada
    int num; //numero total de estruturas na lista ligada
    tic mat[3][3]; //matriz 3x3 onde cada posicao tem uma estrutura do tipo tic
    int player; // indica qual o jogador esta a jogar
    int gmode; //indica qual o modo de jogo,( 2 -> 2players mode | 1 -> 1player mode )
    int state; // onde é guardado, o estado do jogo atualmente (0 - ja terminou | 1 - ainda nao terminou | 2 - acabou de começar)
};
typedef struct matrizsuper supertic;

//Funções de inicialização, libertação, impressão do tabuleiro de jogo e interface de texto
void printSuperTic(supertic *s, int nlin, int ncol); // imprime o jogo completo so seu estado atual
supertic * criaSuperTic(int nLin, int nCol); // inicializa o tabuleiro do jogo com estrutura dinamica
void libertaSuperTic(supertic *s, int nLin, int nCol); //funcao para libertar a matriz
void menuSuperTic(supertic *s, int x, int y); //funcao para comecar o menu do novo jogo

//Funções de execução de jogadas
void playSuperTicPc(supertic *s, int x, int y, int *a, int *b); //funcao que inicia a logica do jogo com o computador
void playSuperTic(supertic *s, int x, int y, int *a, int *b); //funcao que inicia a logica do jogo com o jogador
void playSavedGame(supertic *s); //funcao que executa as jogadas de um ficheiro

//Funções auxiliares na execução de jogadas
void moveSuperTic(int *x,int *y,int a,int b); //funcao que possibilita a movimentacao para um quadrado especifico
void changePlayer(supertic *s); //funcao que altera o jogador atual
void selectStartingSquare(supertic *s,int *x,int *y); //funcao que escolha um novo quadrado especifico do tipo tic
void selectRandomSquare(supertic *s,int *x,int *y);//funcao que escolha um novo quadrado aleatorio do tipo tic

//Funções de verificação de tabuleiro
int verifySuperTic(supertic *s); // funcao que verifica se algum combinacao de vitoria ja foi conseguida
int verifyAvailableSquares(supertic *s); //funcao que verifica se ainda existem posicoes validas para continuar o jogo


//Funções de manipulação de ficheiros
void saveGame(supertic *s); //funcao que guarda o jogo atual
phist loadGameSt(supertic *s); //funcao que le um ficheiro com a lista ligada de jogadas
void export(supertic *s); //funcao para debugging
int checkFile(); //funcao que verifica se um ficheiro de jogo existe



#endif //TRABALHO_SUPERTIC_H
