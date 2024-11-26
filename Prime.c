#include <stdio.h>

void main(){
    int input;
    printf("enter a number\n");
    scanf("%i", &input);
    int i = 2;
    for (; i < input; i++){
        if (input % i == 0)
        {
            //printf("%i", i);
            break;
        }
        
    }
    i == input ? printf("%i is a prime", input) : printf("%i is not a prime", input);
}