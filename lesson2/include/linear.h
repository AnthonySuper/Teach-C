#ifndef _LINEAR_H
#define _LINEAR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _point {
    double x, y;
} Point;

typedef struct _matrix {
    double data[2][2];
} Matrix;

// Apply the matrix M to the point p and return the resulting point
// This is done by performing matrix multiplication (M*p)
// see https://en.wikipedia.org/wiki/Matrix_multiplication
Point matrixTransform(Matrix m, Point p);

Matrix matrixMultiply(Matrix a, Matrix b);

// Turn a matrix into a string you make with malloc
// String should look like "[[a,b],[c,d]]".
// Use %f as the format specifier in sprintf.
const char* matrixToString(Matrix m);

#endif
