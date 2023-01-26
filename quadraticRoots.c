#include <stdio.h>
#include <math.h>
#include "quadraticRoots.h"

QuadraticRootsResult findRoots(long double a, long double b, long double c){
    QuadraticRootsResult result;

    long double D = (b*b) - (4*a*c);
    if(D < 0){
        result.noRealRoots = 1;
    }
    else if(D == 0){
        result.x1 = (-1*(b))/(2*a);
        result.x2 = result.x1;
    }
    else{
        result.x1 = (-1*(b) + sqrtl(D))/(2*a);
        result.x2 = (-1*(b) - sqrtl(D))/(2*a);
    }

    return result;
}