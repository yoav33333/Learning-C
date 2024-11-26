#include <stdio.h>
#include <math.h>



void main(){
    double a, b;
    printf("enter a");
    scanf("%lf",&a);
    printf("enter b");
    scanf("%lf",&b);
    double c = sqrt((a*a)+(b*b));
    //c=a*a+b*b;
    printf("%f\n",c);
}