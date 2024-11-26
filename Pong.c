#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define SleepTime 40
#define WIDTH 30
#define HEIGHT 15
#define PanelLength 5

typedef enum {Up, Down, Left, Right, None}Diraction;
Diraction Pdir;
int scoreL, scoreR;

typedef struct pos{
    int x;
    int y;
}pos;
typedef struct Ball{
    Diraction VerticalD;
    Diraction horizontalD;
    int x;
    int y;
}Ball;

Ball ball; 


pos LeftPanel;
pos RightPanel;
int isGameOver;


char field[HEIGHT][WIDTH];


void Logic();
void Input();
void Init();
void Draw();

int main(int argc, char const *argv[]){
    Init();
    while (isGameOver){
        Draw();
        Input();
        Logic();
        Sleep(40);
    }
    
        
    return 0;
}

void Init(){
    for(int i = 0; i< HEIGHT; i++){
        for(int j = 0; j< WIDTH; j++){
            field[i][j] = ' ';
        }
    }
    LeftPanel.x = 1;
    LeftPanel.y = HEIGHT/2;
    RightPanel.x = WIDTH-2;
    RightPanel.y = HEIGHT/2;
    scoreL = 0;
    scoreR = 0;
    isGameOver = 1;
    Pdir = None;
    ball.horizontalD = Right;
    ball.VerticalD = Up;
    ball.x = WIDTH/2;
    ball.y = HEIGHT/2;
}



void Input(){
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            Pdir = Up;
            break;
        case 's':
            Pdir = Down;
            break;
        case 'x':
            isGameOver = 0;
            break;
        default:
            Pdir = None;
            break;
        }
    }
}
void resetField() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            field[row][col] = (col == WIDTH / 2) ? '|' : ' ';
        }
    }
}

void moveBall(){
    if(ball.horizontalD == Right){
        ball.x++;
    }
    else{
        ball.x--;
    }
    if(ball.VerticalD == Up){
        ball.y--;
    }
    else{
        ball.y++;
    }
}

void col(){
    if(ball.horizontalD == Right){
        if(ball.x == RightPanel.x && abs(ball.y - RightPanel.y) < PanelLength/2){
            ball.horizontalD = Left;
        }
        else if (ball.x == WIDTH){
            ball.x = WIDTH/2;
            ball.y = HEIGHT/2;
            scoreL++;
        }
        
    }
    else if(ball.x == LeftPanel.x && abs(ball.y - LeftPanel.y) < PanelLength/2){
        ball.horizontalD = Right;
    }
    else if (ball.x == 0){
        ball.x = WIDTH/2;
        ball.y = HEIGHT/2;
        scoreR++;
    }

    if(ball.y == 0 || ball.y == HEIGHT-1){
        ball.VerticalD = ball.VerticalD == Up ? Down : Up;
    } 
}

void Logic(){
    resetField();
    LeftPanel.x = 1;
    moveBall();
    col();
    switch (Pdir){
        case Down:{
            if(LeftPanel.y != HEIGHT-3){
                LeftPanel.y++;     
            }
            break;
        }
        case Up:{
            if(LeftPanel.y != 2){
                LeftPanel.y--;
            }
            break;
        }
        
        default:
            break;
    }
    RightPanel.y = ball.y;
    for(int i = 0; i< PanelLength; i++){
        field[LeftPanel.y-(PanelLength/2)+i][LeftPanel.x] = '|';
        field[RightPanel.y-(PanelLength/2)+i][RightPanel.x] = '|';
    }


    field[ball.y][ball.x] = 'O';

}

void Draw(){
    system("cls");
    for(int i = 0; i< HEIGHT; i++){
        for(int j = 0; j< WIDTH; j++){
            if(i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH -1){
                printf("#");
            }
            else{
                printf("%c", field[i][j]);
            }
        }
        printf("\n");
    }
    printf("score left: %d   score right: %d", scoreL, scoreR);
    printf("\n LeftPanel: x: %d, y: %d", LeftPanel.x, LeftPanel.y);
    printf("\n RightPanel: x: %d, y: %d", RightPanel.x, RightPanel.y);
    printf("\n Ball: x: %d, y: %d", ball.x, ball.y);
}