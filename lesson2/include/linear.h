#ifndef _LINEAR_H
#define _LINEAR_H

typedef struct _point {
    double x, y;
} Point;

typedef struct _matrix {
    double[2][2] data
} Matrix;

Point matrixTransform(Point p, Matrix m);

Matrix matrixMultiply(Matrix a, Matrix b);

#endif
