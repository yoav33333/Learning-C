#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define SCREEN_WIDTH 30
#define SCREEN_HEIGHT 15

#define PADDLE_HEIGHT 4
#define BALL_SIZE 1

int gameOver = 1;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int height;
} Paddle;

typedef struct {
    Point position;
    Point direction;
} Ball;

void initialize(Paddle *paddle1, Paddle *paddle2, Ball *ball) {
    paddle1->position.x = 2;
    paddle1->position.y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    paddle1->height = PADDLE_HEIGHT;

    paddle2->position.x = SCREEN_WIDTH - 3;
    paddle2->position.y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    paddle2->height = PADDLE_HEIGHT;

    ball->position.x = SCREEN_WIDTH / 2;
    ball->position.y = SCREEN_HEIGHT / 2;
    ball->direction.x = (rand() % 2) ? 1 : -1;
    ball->direction.y = (rand() % 2) ? 1 : -1;
}

void draw(Paddle paddle1, Paddle paddle2, Ball ball) {
    system("cls");

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            if (x == paddle1.position.x && y >= paddle1.position.y && y < paddle1.position.y + paddle1.height) {
                printf("|");
            } else if (x == paddle2.position.x && y >= paddle2.position.y && y < paddle2.position.y + paddle2.height) {
                printf("|");
            } else if (x == ball.position.x && y == ball.position.y) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update(Paddle *paddle1, Paddle *paddle2, Ball *ball) {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'q') {
            gameOver = 0;
            return;
        }
        if (ch == 'w' && paddle1->position.y > 0) {
            paddle1->position.y--;
        } else if (ch == 's' && paddle1->position.y < SCREEN_HEIGHT - paddle1->height) {
            paddle1->position.y++;
        } else if (ch == 'o' && paddle2->position.y > 0) {
            paddle2->position.y--;
        } else if (ch == 'l' && paddle2->position.y < SCREEN_HEIGHT - paddle2->height) {
            paddle2->position.y++;
        }
    }

    ball->position.x += ball->direction.x;
    ball->position.y += ball->direction.y;

    if (ball->position.y <= 0 || ball->position.y >= SCREEN_HEIGHT - 1) {
        ball->direction.y = -ball->direction.y;
    }

    if (ball->position.x == paddle1->position.x + 1 && ball->position.y >= paddle1->position.y && ball->position.y < paddle1->position.y + paddle1->height) {
        ball->direction.x = -ball->direction.x;
    } else if (ball->position.x == paddle2->position.x - 1 && ball->position.y >= paddle2->position.y && ball->position.y < paddle2->position.y + paddle2->height) {
        ball->direction.x = -ball->direction.x;
    }

    if (ball->position.x <= 0 || ball->position.x >= SCREEN_WIDTH - 1) {
        ball->position.x = SCREEN_WIDTH / 2;
        ball->position.y = SCREEN_HEIGHT / 2;
        ball->direction.x = (rand() % 2) ? 1 : -1;
        ball->direction.y = (rand() % 2) ? 1 : -1;
    }
}

int main() {
    srand(time(0));

    Paddle paddle1, paddle2;
    Ball ball;
    initialize(&paddle1, &paddle2, &ball);

    while (gameOver) {
        draw(paddle1, paddle2, ball);
        update(&paddle1, &paddle2, &ball);
        Sleep(50); // Delay to control game speed
    }

    return 0;
}
