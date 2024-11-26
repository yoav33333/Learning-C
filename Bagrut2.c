#include <stdio.h>

#define W 3
#define H 3

int array[H][W] = { {1,1,1},
                    {1,2,2},
                    {1,2,3}};

int isCorner();

int main(int argc, char const *argv[]){
    int a = isCorner(array, H, W);
    printf("%d", a);
    return 0;
}

int isCorner(int array[][W], int h, int w){
    if (h != w){
        return 0;
    }
    for (int i = 0; i < h; i++){
        for (int j = i; j < w; j++){
            if(array[i][j] != i+1){
                return 0;
            }
        }
        for (int j = i; j < w; j++){
            if(array[j][i] != i+1){
                return 0;
            }
        }
        
    }
    return 1;
    
}
