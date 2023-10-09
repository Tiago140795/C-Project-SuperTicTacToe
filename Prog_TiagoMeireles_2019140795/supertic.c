//
// Created by Tiago Meireles on 24/05/2022.
//

#include "supertic.h"

void printSuperTic(supertic *s, int nlin, int ncol) {
    int i , j , k  ,l, con=0 ,max=nlin*ncol;
    printf("\n    [Y]   [0]         [1]         [2]      ");
    printf("\n [X] ╔═══════════╦═══════════╦═══════════╗\n");
    for(l=0;l<nlin && con < max;l++) {
        for (i=0; i < nlin ; i++) {
            for (j = 0; j < ncol; j++) {
                if(j==0 && i==1)
                    printf(" [%d] ║ ",l);
                else if(j==0)
                    printf("     ║ ");
                else
                printf(" ║ ");
                for (k = 0; k < ncol; k++) {
                    if(s->mat[l][j].p == NULL)
                        printf("\nErro no alvo do ponteiro");
                    if(s->mat[l][j].p[i][k] != '_' && s->mat[l][j].p[i][k] != 'O' && s->mat[l][j].p[i][k] != 'X' )
                        printf("\nErro no valor [%c] da celula [%d][%d] no quadrado [%d]\n",s->mat[l][j].p[i][k],i,k,i+l);
                    else
                        printf("[%c]", s->mat[l][j].p[i][k]);
                }
            }
            con++;
            printf(" ║ \n");
        }
        if(l<2)
            printf("     ╠═══════════╬═══════════╬═══════════╣\n");
        if(l==2 && con < max)
            l=0;
    }
    printf("     ╚═══════════╩═══════════╩═══════════╝\n");
}

void libertaSuperTic(supertic *s, int nLin, int nCol) {
    for (int i = 0; i < nLin; i++){
        for (int j = 0; j < nCol; j++) {
            libertaMat(s->mat[i][j].p, 3);
        }
    }
    while(s->hist->prox!=NULL)
        deleteHist(s->hist);
    free(s->hist);
    free(s);
}


supertic * criaSuperTic(int nLin, int nCol){
    supertic *s=NULL;
    s = malloc(sizeof(supertic));
    if(s == NULL) {
        printf("\nErro na allocação de memória.\n");
        return NULL;
    }
    for(int i=0; i<nLin; i++){
        for(int j=0; j<nCol; j++) {
            s->mat[i][j].p = criaMat(3, 3);
            if (s->mat[i][j].p == NULL) {
                printf("\nErro na allocação de memória.\n");
                libertaMat(s->mat[i][j].p,3-j);
                return NULL;
            }
        }
    }
    s->hist = NULL;
    s->num=0;
    s->player=1;
    s->state=2;
    return s;
}

int verifySuperTic(supertic *s){
    //Verifica quando o quadrado ganha com caracter 'X'
    if(verifyTic(s->mat[0][0].p)==1 && verifyTic(s->mat[0][1].p)==1 && verifyTic(s->mat[0][2].p)==1) //verifica linhas horizontais
            return 1;
    if(verifyTic(s->mat[1][0].p)==1 && verifyTic(s->mat[1][1].p)==1 && verifyTic(s->mat[1][2].p)==1)
            return 1;
    if(verifyTic(s->mat[2][0].p)==1 && verifyTic(s->mat[2][1].p)==1 && verifyTic(s->mat[2][2].p)==1)
         return 1;

    if(verifyTic(s->mat[0][0].p)==1 && verifyTic(s->mat[1][0].p)==1 && verifyTic(s->mat[2][0].p)==1)//verifica linhas verticias
        return 1;
    if(verifyTic(s->mat[0][1].p)==1 && verifyTic(s->mat[1][1].p)==1 && verifyTic(s->mat[2][1].p)==1)
        return 1;
    if(verifyTic(s->mat[0][2].p)==1 && verifyTic(s->mat[1][2].p)==1 && verifyTic(s->mat[2][2].p)==1)
        return 1;

    if(verifyTic(s->mat[0][0].p)==1 && verifyTic(s->mat[1][1].p)==1 && verifyTic(s->mat[2][2].p)==1)//verifica linhas diagonais
        return 1;
    if(verifyTic(s->mat[0][2].p)==1 && verifyTic(s->mat[1][1].p)==1 && verifyTic(s->mat[0][0].p)==1)
        return 1;

    //Verifica quando o quadrado ganha com caracter 'O'
    if(verifyTic(s->mat[0][0].p)==2 && verifyTic(s->mat[0][1].p)==2 && verifyTic(s->mat[0][2].p)==2) //verifica linhas horizontais
        return 2;
    if(verifyTic(s->mat[1][0].p)==2 && verifyTic(s->mat[1][1].p)==2 && verifyTic(s->mat[1][2].p)==2)
        return 2;
    if(verifyTic(s->mat[2][0].p)==2 && verifyTic(s->mat[2][1].p)==2 && verifyTic(s->mat[2][2].p)==2)
        return 2;

    if(verifyTic(s->mat[0][0].p)==2 && verifyTic(s->mat[1][0].p)==2 && verifyTic(s->mat[2][0].p)==2)//verifica linhas verticias
        return 2;
    if(verifyTic(s->mat[0][1].p)==2 && verifyTic(s->mat[1][1].p)==2 && verifyTic(s->mat[2][1].p)==2)
        return 2;
    if(verifyTic(s->mat[0][2].p)==2 && verifyTic(s->mat[1][2].p)==2 && verifyTic(s->mat[2][2].p)==2)
        return 2;

    if(verifyTic(s->mat[0][0].p)==2 && verifyTic(s->mat[1][1].p)==2 && verifyTic(s->mat[2][2].p)==2)//verifica linhas diagonais
        return 2;
    if(verifyTic(s->mat[0][2].p)==2 && verifyTic(s->mat[1][1].p)==2 && verifyTic(s->mat[0][0].p)==2)
        return 2;
    return 0;
}

void moveSuperTic(int *x,int *y,int a,int b){
    *x=a,
    *y=b;
}

void changePlayer(supertic *s){
    if(s->player==1) {
        s->player = 2;
    }
    else {
        s->player = 1;
    }
}

int verifyAvailableSquares(supertic *s){
    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            if (verifyAvailableSpaces(s->mat[i][j].p) == 1)
                return 1;
        }
    }
    return 0;
}

void playSuperTicPc(supertic *s, int x, int y, int *a, int *b) {
    int cmd=0;  s->state=1;
    do {
        if (verifySuperTic(s) == 1 || verifySuperTic(s) == 2) {
            printf("\nThe computer has won!\n");
            s->state = 0;
            return;
        } else if (verifyAvailableSquares(s) == 0) {
            printf("\nThe game has ended in a draw!\n");
            s->state = 0;
            return;
        }
            do {
                *a = intUniformRnd(0, 2);
                *b = intUniformRnd(0, 2);
                if (verifyTic(s->mat[*a][*b].p) == 1 || verifyTic(s->mat[*a][*b].p) == 2 ||
                    verifyAvailableSpaces(s->mat[*a][*b].p) == 0) {
                    selectRandomSquare(s, &x, &y);
                } else
                    cmd = 1;
            } while (cmd != 1);

            if (*a > 2 || *a < 0 || *b > 2 || *b < 0)
                cmd = 1;
            else if (s->mat[x][y].p[*a][*b] != '_')
                cmd = 2;
            else
                cmd = 0;
    }while (cmd != 0);

        if (s->player == 1)
            setPos(s->mat[x][y].p, *a, *b, 'X');
        else
            setPos(s->mat[x][y].p, *a, *b, 'O');
        s->num++;
        s->hist = insertHist(s->hist, s->num, s->player, x, y, *a, *b);
        changePlayer(s);

        if (verifySuperTic(s) == 1 || verifySuperTic(s) == 2) {
            printf("\nThe computer has won!\n");
            s->state = 0;
        } else if (verifyAvailableSquares(s) == 0) {
            printf("\nThe game has ended in a draw!\n");
            s->state = 0;
        }
        printf("\nThe computer, has played on the square [%d][%d].\n", *a, *b);
}

void playSuperTic(supertic *s, int x, int y, int *a, int *b) {
    int cmd=0;  s->state=1;

        if (verifySuperTic(s) == 1 || verifySuperTic(s) == 2) {
            printf("\nPlayer %d won!\n", s->player);
            s->state = 0;
            return;
        } else if (verifyAvailableSquares(s) == 0) {
            printf("\nThe game has ended in a draw!\n");
            s->state = 0;
            return;
        } else if (verifyTic(s->mat[*a][*b].p) == 1 || verifyTic(s->mat[*a][*b].p) == 2 ||verifyAvailableSpaces(s->mat[*a][*b].p) == 0) {
            printf("\nThe square you are trying to go was completed or was won.");
            printSuperTic(s, 3, 3);
            do{
                printf("\n\t1 - To select the next square\n\t2 - For the next square to be random\nAnswer:");
                fflush(stdout);
                fflush(stdin);
                scanf("%d", &cmd);
            }while(cmd > 2 || cmd <1);
            if(cmd==1)
                selectStartingSquare(s, &x, &y);
            else
                selectRandomSquare(s,&x,&y);
        }
        do {
            printTic(s->mat[x][y].p, 3, 3);;
            printf("\nPlayer 1 is 'X', Player 2 is 'O'.");
            printf("\nYou are in the square [%d][%d].", x, y);
            printf("\nChoose your move player %d.", s->player);
            printf("\nEnter the 'X' coordenate:");
            fflush(stdin);
            scanf("%d", a);
            printf("\nEnter the 'Y' coordenate:");
            fflush(stdin);
            scanf("%d", b);

            if (*a > 2 || *a < 0 || *b > 2 || *b < 0) {
                printf("\nInvalid move, out of bounds, please try again.\n");
                cmd = 1;
            } else if (s->mat[x][y].p[*a][*b] != '_') {
                printf("\nInvalid move, please try again.\n");
                cmd = 2;
            } else
                cmd = 0;
        } while (cmd != 0);


        if (s->player == 1)
            setPos(s->mat[x][y].p, *a, *b, 'X');
        else
            setPos(s->mat[x][y].p, *a, *b, 'O');
        s->num++;
        s->hist = insertHist(s->hist,s->num,s->player,x,y,*a,*b);
        changePlayer(s);

        if (verifySuperTic(s) == 1 || verifySuperTic(s) == 2) {
            printf("\nPlayer %d won!\n", s->player);
            s->state = 0;
        }
        else if (verifyTic(s->mat[*a][*b].p) == 1 || verifyTic(s->mat[*a][*b].p) == 2 || verifyAvailableSpaces(s->mat[*a][*b].p) == 0) {
            printf("\nThe square you are trying to go was completed or was won.");
            printSuperTic(s, 3, 3);
            do{
                printf("\n\t1 - To select the next square\n\t2 - For the next square to be random\nAnswer:");
                fflush(stdout);
                fflush(stdin);
                scanf("%d", &cmd);
            }while(cmd > 2 || cmd <1);
            if(cmd==1)
                selectStartingSquare(s, &x, &y);
            else
                selectRandomSquare(s,&x,&y);
        }
        else if(verifyAvailableSquares(s)==0){
            printf("\nThe game has ended in a draw!\n");
            s->state = 0;
        }
}

void playSavedGame(supertic *s){
    phist new = s->hist;
    phist aux;
    while(new!= NULL){
        if (verifyTic(s->mat[new->x][new->y].p) == 1 || verifyTic(s->mat[new->x][new->y].p) == 2 || verifyAvailableSpaces(s->mat[new->x][new->y].p) == 0) {
            printf("\nThe square you are trying to go was completed or was won.");
        }
        if ( new->a > 2 || new->a < 0 || new->b > 2 || new->b < 0 ) {
            printf("\nMove [%d] is invalid, out of bounds.", s->num);
        }
        if( s->mat[new->x][new->y].p[new->a][new->b] != '_') {
            printf("\nMove [%d] is invalid, that square is taken.", s->num);
        }
        if (new->player == 1)
            setPos(s->mat[new->x][new->y].p, new->a, new->b, 'X');
        else
            setPos(s->mat[new->x][new->y].p, new->a, new->b, 'O');

        if (verifySuperTic(s) == 1 || verifySuperTic(s) == 2) {
            printf("\nPlayer %d won!\n", new->player);
            s->state = 0;
        }else if(verifyAvailableSquares(s)==0){
            printf("\nThe game has ended in a draw!\n");
            s->state = 0;
        }
        aux = new;
        new = new->prox;
    }
    menuSuperTic(s,aux->a,aux->b);
}

void saveGame(supertic *s) {
    remove("../jogo.bin");
    FILE *file = fopen("../jogo.bin", "wb");
    if (file == NULL){
        printf("\nError opening the file.");
        return;
    }
    phist new = s->hist;

    fwrite(&s->num, sizeof(int),1,file);
    fwrite(&s->gmode, sizeof(int),1,file);
    printf("\nSaving move [%d] to file...",new->num);
    while(new!=NULL) {
        fwrite(&new->num,sizeof(int),1,file);
        fwrite(&new->player,sizeof(int),1,file);
        fwrite(&new->x,sizeof(int),1,file);
        fwrite(&new->y,sizeof(int),1,file);
        fwrite(&new->a,sizeof(int),1,file);
        fwrite(&new->b,sizeof(int),1,file);
        //fwrite(new,sizeof(hist),1,file);
        new = new->prox;
    }
    fclose(file);
    free(new);
    printf("\nSaving complete.");
}

void export(supertic *s){
    phist new = s->hist;
    char filename[64], aux[64];
    printf("\nExporting to a textfile...\n\tFilename (without .txt): ");
    fflush(stdout);
    scanf("%s", aux);
    strcpy(filename, "../");
    strcat(filename, aux);
    strcat(filename, ".txt");

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file,"%d",s->num);
    fprintf(file,"\t%d",s->gmode);
    while(new) {
        fprintf(file,"\n%d\t%d\t%d%d\t%d%d", new->num, new->player, new->x, new->y, new->a, new->b);
        new = new->prox;
    }
    fclose(file);
    free(new);

}

phist loadGameSt(supertic *s){
    FILE * file;
        file = fopen("../jogo.bin","rb");
        if(file == NULL){
            printf("\nError opening the file.");
            return s->hist;
        }
    phist new=malloc(sizeof(hist));
    s->hist = new;

    printf("\nLoading...");
    fread(&s->num,sizeof(int),1,file);
    fread(&s->gmode,sizeof(int),1,file);
    for(int i=0; i<s->num && fseek(file,0,SEEK_CUR) != EOF ; ++i){
        fread(&new->num,sizeof(int),1,file);
        fread(&new->player,sizeof(int),1,file);
        fread(&new->x,sizeof(int),1,file);
        fread(&new->y,sizeof(int),1,file);
        fread(&new->a,sizeof(int),1,file);
        fread(&new->b,sizeof(int),1,file);
        //fread(&new,sizeof(hist),1,file);
        new->prox=NULL;

        new = insertHist(new,new->num,new->player,new->x,new->y,new->a,new->b);
        new = new->prox;
        //printf("\nLoading[%d]...",i);
    }
    s->hist = deleteHist(s->hist);
    fclose(file);
    free(new);
    printf("\nLoading complete.\n");
    return s->hist;
}

int checkFile() {
    int cmd;
    FILE *file = fopen("../jogo.bin", "rb");
    if (file != NULL) {
        do {
            printf("\nWelcome back!\nDo you want to continue from last time?\n\t1 - Yes\n\t2 - No\nAnswer:");
            fflush(stdout);
            fflush(stdin);
            scanf("%d", &cmd);
        } while (cmd > 2 || cmd < 1);

        if (cmd == 1) {
            printf("\nResuming the game...");
            return 1;
        } else
            return 0;

    }
}

void selectStartingSquare(supertic *s,int *x,int *y){
    int cmd=0;
    do{
            if(s->state==2)
                printf("\nSelect the starting square.");
            else if(s->state==1)
                printf("\nPlease select the next square.");
            printf("\nEnter the 'X' coordenate:");
            fflush(stdin);
            scanf("%d", x);
            printf("\nEnter the 'Y' coordenate:");
            fflush(stdin);
            scanf("%d", y);
            if (*x > 2 || *x < 0 || *y > 2 || *y < 0) {
                printf("\n'X' and 'Y' must be between 0 and 2.");
            }
            else if (verifyTic(s->mat[*x][*y].p) == 1 || verifyTic(s->mat[*x][*y].p) == 2 || verifyAvailableSpaces(s->mat[*x][*y].p) == 0)
                printf("\nThe square you are trying to go was completed or was won.");
            else{
                cmd = 1;
            }
    } while (cmd != 1);
}

void selectRandomSquare(supertic *s,int *x,int *y){
    int cmd=0;
        do {
            *x = intUniformRnd(0, 2);
            *y = intUniformRnd(0, 2);
            if (verifyTic(s->mat[*x][*y].p) == 1 || verifyTic(s->mat[*x][*y].p) == 2 || verifyAvailableSpaces(s->mat[*x][*y].p) == 0)
                cmd=0;
            else
                cmd=1;
        } while (cmd != 1);
}

void menuSuperTic(supertic *s, int x, int y){
    int a=0,b=0,cmd=0,pl;

    if (x>2 || y>2)
        selectStartingSquare(s,&x,&y);

    if(s->gmode==1) {
        do {
            printf("\nDo you want to be player 1 or player 2? (1 or 2)\nAnswer:");
            scanf("%d", &pl);
        } while (pl < 1 || pl > 2);
    }
        do {
            printf("\n<[Super-Tic-Tac-Toe]>\n\t1 - To show all of the board.\n\t2 - To show current square.\n\t3 - To play next move."
                   "\n\t4 - To see previous moves.\n\t5 - To save current game.\n\t6 - To quit.\nAnswer:");
            fflush(stdout);
            fflush(stdin);
            scanf("\t%d", &cmd);

            switch (cmd) {
                case 1: printSuperTic(s,3, 3);
                        break;

                case 2: printf("\nYou are in the square [%d][%d].\n", x, y);
                        printTic(s->mat[x][y].p,3,3);
                        break;

                case 3: if(s->gmode==2) {
                            playSuperTic(s, x, y, &a, &b);
                        }
                        else if(s->gmode==1){
                            if(pl==2){
                                playSuperTicPc(s, x, y, &a, &b);
                                pl--;
                            }else if(pl==1){
                                playSuperTic(s, x, y, &a, &b);
                                pl++;
                            }
                        }else
                            printf("\nError on playing next move.");
                        if(s->state == 0){
                            libertaSuperTic(s,3,3);
                            cmd=6;
                            break;
                        }
                        else
                            moveSuperTic(&x, &y, a, b);
                        break;

                case 4: printRecentHist(s->hist, s->num);
                        break;

                case 5: if(s->num>0) {
                        saveGame(s);
                        export(s);
                    }
                        else
                            printf("\nYou do not have enough moves to save.");
                        break;

                case 6: do{
                            printf("\nAre you sure you want to quit? (All unsaved moves will be deleted)\n\t1 - Yes.\n\t2 - No\nAnswer:");
                            fflush(stdout);
                            fflush(stdin);
                            scanf("%d", &cmd);
                            }while(cmd > 2 || cmd <1);
                            if(cmd==1) {
                                libertaSuperTic(s,3,3);
                                cmd = 6;
                            }
                             break;
                default: break;
            }
        }while( cmd != 6 );
}