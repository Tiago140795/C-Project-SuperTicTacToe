#include "matdin.h"


void libertaMat(char** p, int nLin){
    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

char** criaMat(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL) {
        printf("\nErro na allocação de memória.\n");
        return NULL;
    }

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char*) * nCol);
        if(p[i] == NULL){
            printf("\nErro na allocação de memória.\n");
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++) {
            p[i][j] = '_';
            if (p[i][j] != '_') {
                printf("\nErro no valor da celula [%d][%d]=[%c].", i, j, p[i][j]);
                //p[i][j] = '_';
            }
        }
    }
    return p;
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}

char getPos(char **p, int x, int y){
    return p[x][y];
}

void mostraMat(char **p, int nLin, int nCol){
    int i,j;
    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%c\t", p[i][j]);
        putchar('\n');
    }
}