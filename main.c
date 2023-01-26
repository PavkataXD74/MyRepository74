#include <stdio.h>
#include "quadraticRoots.h"

int main(){
    QuadraticRootsResult result;
    
    printf("Testing with int:\n");
    result = findRoots(1, -3, 2);
    if(result.noRealRoots == 1){
        printf("no real roots");
    }
    else{
        printf("%d\n", (int)result.x1);
        printf("%d\n", (int)result.x2);
    }
    printf("\n");


    printf("Testing with float:\n");
    result = findRoots(1.6, -4.1, 2.5);
    if(result.noRealRoots == 1){
        printf("no real roots");
    }
    else{
        printf("%f\n", (float)result.x1);
        printf("%f\n", (float)result.x2);
    }
    printf("\n");


    printf("Testing with double:\n");
    result = findRoots(2.89, -8.01, 5.12);
    if(result.noRealRoots == 1){
        printf("no real roots");
    }
    else{
        printf("%lf\n", (double)result.x1);
        printf("%lf\n", (double)result.x2);
    }
    printf("\n");

    return 0;
}