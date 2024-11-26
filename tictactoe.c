#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define Size 3

char board[Size][Size];
char currentPlayer = 'X';
int openSlots = pow(Size, 2);

void initializeBoard() {
    for (int row = 0; row < Size; row++) {
        for (int col = 0; col < Size; col++) {
            board[row][col] = ' ';
        }
    }
}

void printBoard(){
    for(int i = 0; i< Size; i++){
        for(int j = 0; j< Size; j++){
            printf("%c", board[i][j]);
            if (j < Size-1){
                printf(" | ");
            }
        }
        if (i < Size-1){
            printf("\n---------\n");
        }
        else{
            printf("\n");
        }
    }
}

void switchPlayer() {
    if (currentPlayer == 'X'){
        currentPlayer = 'O';
    }
    else{
        currentPlayer = 'X';
    }
    
}

void insertPlayerMove() {
    int playerMove;
    printf("\nEnter position (1-9): ");
    scanf("%d", &playerMove);
    
    int row = (playerMove - 1) / Size;
    int col = (playerMove - 1) % Size;
    
    if (board[Size-row-1][col] == ' ') {
        board[Size-row-1][col] = currentPlayer;
        openSlots--;
    } 
    else {
        printf("Invalid move. Try again.\n");
        insertPlayerMove();
    }
}

int isDraw(){
    return openSlots == 0;
}

int isWin() {
    for (int i = 0; i < Size; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return 1;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}

int main(int argc, char const *argv[]){
    initializeBoard();
    while (1){
        system("@cls||clear");
        printBoard();
        insertPlayerMove();
        if(isWin()){
            printBoard();
            printf("%c WON", currentPlayer);
            break;
        }
        else if (isDraw()){
            printBoard();
            printf("draw");
            break;        
        }
        switchPlayer();
    }
    
    

    return EXIT_SUCCESS;
}
