#include <stdio.h>

char string[] = {'1','2','4', '1','2','4'};
int len = sizeof(string)/sizeof(string[0]);

int isDouble(char str[], int len){
    for(int i = 0; i<len/2; i++){
        if(str[i] != str[len/2+i]){
            return 0;
        } 
    }
    return 1;
}

int main(int argc, char const *argv[]){
    printf("%d", isDouble(string, len));
    return 0;
}
