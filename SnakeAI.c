#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Dimensions of the game field
#define WIDTH 20
#define HEIGHT 20

// Direction enum for snake movement
typedef enum { STOP = 0, LEFT, RIGHT, UP, DOWN } Direction;

// Snake structure
typedef struct {
    int x, y;
} SnakeSegment;

// Global variables
int gameOver;
int score;
int fruitX, fruitY;
int nTail;
SnakeSegment tail[100];
Direction dir;

// Function prototypes
void setup();
void draw();
void input();
void logic();
int main() {
    setup();
    while (!gameOver) {
        input();
        draw();
        logic();
        Sleep(100); // Sleep for 100 milliseconds
    }
    return 0;
}

void setup() {
    gameOver = 0;
    dir = STOP;
    tail[0].x = WIDTH / 2;
    tail[0].y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 1;
}

void draw() {
    system("cls"); // Clear the console
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");
            if (i == tail[0].y && j == tail[0].x)
                printf("O"); // Draw head
            else if (i == fruitY && j == fruitX)
                printf("@"); // Draw fruit
            else {
                int isTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tail[k].x == j && tail[k].y == i) {
                        printf("o");
                        isTail = 1;
                    }
                }
                if (!isTail) printf(" ");
            }
            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void logic() {
    // Update tail positions
    SnakeSegment prev = tail[0];
    SnakeSegment prev2;
    tail[0].x += (dir == LEFT) ? -1 : (dir == RIGHT) ? 1 : 0;
    tail[0].y += (dir == UP) ? -1 : (dir == DOWN) ? 1 : 0;
    
    for (int i = 1; i < nTail; i++) {
        prev2 = tail[i];
        tail[i] = prev;
        prev = prev2;
    }

    // Check for collision with walls
    if (tail[0].x >= WIDTH || tail[0].x < 0 || tail[0].y >= HEIGHT || tail[0].y < 0)
        gameOver = 1;

    // Check for collision with self
    for (int i = 1; i < nTail; i++) {
        if (tail[i].x == tail[0].x && tail[i].y == tail[0].y)
            gameOver = 1;
    }

    // Check if the snake ate the fruit
    if (tail[0].x == fruitX && tail[0].y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

