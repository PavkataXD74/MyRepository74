#ifndef QUADRATIC_H
#define QUADRATIC_H

typedef struct QuadraticRootsResult{
    long double x1;
    long double x2;
    long double noRealRoots;
}QuadraticRootsResult;

QuadraticRootsResult findRoots(long double a, long double b, long double c);

#endif