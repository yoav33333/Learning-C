#include <stdio.h>
#include "timsort.c"
#include <time.h> 


int array[] = {5, 21, 7, 23, 19, 10, 6, 15, 1, 3, 2, 12, 9, 14, 13, 11, 4, 8, 18, 16, 17, 20, 22, 24, 5, 3,3 ,34, 53, 34, 354, 43, 43,12,12,354,7,3,5,3,12,43,65};
unsigned int len = sizeof(array) / sizeof(array[0]);

int LinearSearch(int array[], int len, int key){
    for (int i = 0; i < len; i++){
        if (i[array] == key){
            printf("%d\n", i);
            return i;
        }
    }
    printf("%d\n", len);
    return -1;
}

int BinarySearch(int array[], int len, int key){
    int first = 0;
    int last = len;
    int index = 0;
    int mid;
    while (first<=last){
        mid = (first+last)/2;
        if (mid[array] == key){
            printf("%d\n", index);
            return mid;
        }
        else if (mid[array] < key){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }
        index++;
    }
    printf("%d\n", index);
    return -1;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i<len; i++){
        printf("%d, ", i[array]);
    }
    printf("\n");
    timsort(array, len);
    for (int i = 0; i<len; i++){
        printf("%d, ", i[array]);
    }
    printf("\n");
    clock_t t; 
    t = clock(); 
    printf("%d \n", BinarySearch(array, len, 15));
    printf("Time taken: %f \n", clock() - t);
    printf("%d \n", LinearSearch(array, len, 15));
    printf("Time taken: %f \n", clock() - t);
    return 0;
}
