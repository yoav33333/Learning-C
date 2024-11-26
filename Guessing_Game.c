#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool check(int random, int input){
    if (input == random)
    {
        printf("correct \n");
        return 1;
    }
    else{
        printf("wrong \n");
        return 0;
    }
}

void main(){
    int MaxVal = 5;
    srand(time(NULL));
    int input;
    int randomNum = rand() % MaxVal + 1;
    printf("%d\n", randomNum);

    do {
        printf("Enter a number: ");
        scanf("%d", &input);
    }
    while (!check(randomNum, input));

    printf("End");
    
    
}

