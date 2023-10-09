//
// Created by Tiago Meireles on 26/05/2022.
//

#include "jogo.h"

void menu(){
    int cmd=0;
    if(checkFile()==1)
        loadGame();
    do {
        printf("\nWelcome to Super-Tic-Tac-Toe !\n");
        printf("\t1 - To start a new game\n\t2 - To load a game file\n\t3 - To Quit\nAnswer:");
        do {
            fflush(stdout);
            fflush(stdin);
            scanf("%1d", &cmd);
        } while (cmd > 4 || cmd < 1);

        switch (cmd) {
            case 1: gameMode();break;
            case 2: loadGame();break;
            case 3: cmd=3;
            default: break;
        }
    }while(cmd!=3);
    printf("\nUntil next time!\n");
}

void gameMode(){
    int cmd=0;
    do {
        printf("\nSelect the game mode.\n");
        printf("\t1 - Two player mode.\n\t2 - One player mode.\n\t3 - To go back\nAnswer:");
        do {
            fflush(stdout);
            fflush(stdin);
            scanf("%1d", &cmd);
        } while (cmd > 3 || cmd < 1);

        switch (cmd) {
            case 1: newGame(2);
                    break;

            case 2: newGame(1);
                    break;

            default: break;
        }
    }while(cmd!=3);
}

void newGame(int gm){
    supertic *s;
    s = criaSuperTic(3,3);
    s->gmode=gm;
    int x=3,y=3, cmd;
    printf("\nLet's begin!\n");
    do {
        if(s->state==0)
            cmd=3;
        printf("\t1 - To have a random start.\n\t2 - To choose where you start.\n\t3 - To quit.\n");
            do {
                fflush(stdin);
                scanf("%d", &cmd);
            } while (cmd > 3 || cmd < 1);

        fflush(stdin);
        switch (cmd) {
            case 1: selectRandomSquare(s,&x,&y);
                    menuSuperTic(s, x, y);
                    break;

            case 2: menuSuperTic(s, x, y);
                    break;

            case 3: if(s!=NULL)
                        libertaSuperTic(s,3,3);
                    cmd=3;
                    break;

            default: break;
        }

    }while(cmd != 3);
    free(s);
    printf("\nThanks for playing!\n");
}


void loadGame(){
    supertic *s;
    s = criaSuperTic(3,3);
    if(s == NULL) {
        libertaSuperTic(s,3,3);
        return;
    }
    s->hist=loadGameSt(s);
    if(s->hist == NULL) {
        libertaSuperTic(s,3,3);
        return;
    }
    playSavedGame(s);
}

