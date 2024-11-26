#include <stdio.h>

int factorial(int n){
    if (n< 2){
        return 1;
    }
    else{return n * factorial(n-1);}
    
}

void main(){
    printf("%i", factorial(3));
}

