//
// Created by Tiago Meireles on 28/05/2022.
//

#include "historico.h"

int checkHist(phist h){
    if(h == NULL)
        return 1;
    else
        return 0;
}

void printHist(phist h) {
    phist new=h;
    printf("\nMove\tPlayer\t[X-Y]\t[A-B]");
    while (new!= NULL) {
            printf("\n%3d\t%3d\t[%d-%d]\t[%d-%d]", new->num, new->player, new->x, new->y, new->a, new->b);
        new = new->prox;
    }
    free(new);
}

void printRecentHist(phist h,int num){
    int a, lim;
    phist aux = h;
    if(num>0)
        printf("\nNumber of played moves: %d",num);
    else if(num==0) {
        printf("\nThere are not enough moves to show.");
        return;
    }
    do{
        printf("\nHow many moves backwards do you want to see?(1 to 10)\n");
        scanf("%d",&a);
        if(a>num)
            printf("\nThere are not enough moves to show.");
        if(a>10 || a<1)
            printf("\nYou can only see between 1 and 10 moves before.");
    }while(a>10 || a<1 || a>num);
    lim=(num-a)+1;
    printf("\nMove\tPlayer\t[X-Y]\t[A-B]");
    for(int i=lim;i<=num && aux!=NULL;){
        if(i==aux->num) {
            i++;
            printf("\n%3d\t%3d\t[%d-%d]\t[%d-%d]", aux->num, aux->player, aux->x, aux->y, aux->a, aux->b);
        }
        aux = aux->prox;
    }
    printf("\n");
    free(aux);
}

phist insertHist(phist h, int num, int player, int x, int y, int a, int b){
    phist new, aux;

    if((new = malloc(sizeof(hist)))==NULL){
        printf("\nError in the memory allocation.");
        return h;
    }
    newHist(new,num,player,x,y,a,b);
    if(h == NULL) {
        h = new;
    }
    else{
        aux=h;
        while(aux->prox!=NULL)
            aux = aux->prox;
        aux->prox=new;
    }
    return h;
}

void newHist(phist new, int num, int player, int x, int y, int a, int b){
    new->num=num;
    new->player=player;
    new->x=x;
    new->y=y;
    new->a=a;
    new->b=b;
    new->prox = NULL;
}

phist deleteHist(phist h){
    phist new=h;
    phist aux=NULL;
    while(new->prox!=NULL){
        aux = new;
        new = new->prox;
    }
        aux->prox = NULL;
    return h;
}
