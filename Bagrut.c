#include <stdio.h>

//char string[] = {'1','2','4', '1','2','4'};
char str[] = "12366123";
int len = sizeof(str)/sizeof(str[0]);

int isDouble(char str[], int len){
    for(int i = 0; i<len/2; i++){
        if(str[i] != str[len/2+i]){
            return 0;
        } 
    }
    return 1;
}

int main(int argc, char const *argv[]){
    printf("%s", isDouble(str, len)? "true" : "false");
    return 0;
}
