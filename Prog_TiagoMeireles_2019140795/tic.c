//
// Created by Tiago Meireles on 24/05/2022.
//
#include "tic.h"

void printTic(char **p, int nLin, int nCol){
    int i,j;
    printf("    [Y][0][1][2]\n");
    printf(" [X] ╔═══════════╗\n");
    for(i=0; i<nLin; i++){
        printf(" [%d] ║ ",i);
        for(j=0; j<nCol; j++)
            printf("[%c]", p[i][j]);
        printf(" ║ ");
        putchar('\n');
    }
    printf("     ╚═══════════╝\n");
}

int verifyTic(char **p){
    //Verifica quando o tic ganha com caracter 'X'
    if(p[0][0]==p[0][1] && p[0][0]==p[0][2] && p[0][0]=='X') //verifica linhas horizontais
        return 1;
    if(p[1][0]==p[1][1] && p[1][0]==p[1][2] && p[1][0]=='X')
        return 1;
    if(p[2][0]==p[2][1] && p[2][0]==p[2][2] && p[2][0]=='X')
        return 1;

    if(p[0][0]==p[1][0] && p[0][0]==p[2][0] && p[0][0]=='X')//verifica linhas verticias
        return 1;
    if(p[0][1]==p[1][1] && p[0][1]==p[2][1] && p[0][1]=='X' )
        return 1;
    if(p[0][2]==p[1][2] && p[0][2]==p[2][2] && p[0][2]=='X')
        return 1;

    if(p[0][0]==p[1][1] && p[0][0]==p[2][2] && p[0][0]=='X')//verifica linhas diagonais
        return 1;
    if(p[0][2]==p[1][1] && p[0][2]==p[2][0] && p[0][2]=='X')
        return 1;

    //Verifica quando o tic ganha com caracter 'O'
    if(p[0][0]==p[0][1] && p[0][0]==p[0][2] && p[0][0]=='O') //verifica linhas horizontais
        return 2;
    if(p[1][0]==p[1][1] && p[1][0]==p[1][2] && p[1][0]=='O')
        return 2;
    if(p[2][0]==p[2][1] && p[2][0]==p[2][2] && p[2][0]=='O')
        return 2;

    if(p[0][0]==p[1][0] && p[0][0]==p[2][0] && p[0][0]=='O')//verifica linhas verticias
        return 2;
    if(p[0][1]==p[1][1] && p[0][1]==p[2][1] && p[0][1]=='O')
        return 2;
    if(p[0][2]==p[1][2] && p[0][2]==p[2][2] && p[0][2]=='O')
        return 2;

    if(p[0][0]==p[1][1] && p[0][0]==p[2][2] && p[0][0]=='O')//verifica linhas diagonais
        return 2;
    if(p[0][2]==p[1][1] && p[0][2]==p[2][0] && p[0][2]=='O')
        return 2;

    return 0;
}

int verifyAvailableSpaces(char **p){
    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            if (p[i][j] == '_')
                return 1;
        }
    }
    return 0;
}


