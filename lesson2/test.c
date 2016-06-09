#include <stdio.h>
#include <linear.h>
#include <math.h>

#define ERROR(...) \
    do{ \
    printf("\x1b[31m %s ERROR: ",__FUNCTION__); \
    printf(__VA_ARGS__); \
    printf("\x1b[0m"); \
} while(0)

#define SUCCESS(...) do {\
    printf("\x1b[32m %s SUCCESS: ", __FUNCTION__); \
    printf(__VA_ARGS__); \
    printf("\x1b[0m"); \
} while(0)

int doubleSimilar(double a, double b) {
    return (fabs(a - b) < 0.001);
}

int ds(double a, double b) {
    return doubleSimilar(a, b);
}

void testMatrixTransform() {
    Point p;
    p.x = 2;
    p.y = 3;
    Matrix m;
    m.data[0][0] = 1;
    m.data[0][1] = 2;
    m.data[1][0] = 3;
    m.data[1][1] = 4;
    Point res = matrixTransform(m, p);
    if(! (doubleSimilar(res.x, 8) && doubleSimilar(res.y,18)) ){
        ERROR("Expected (8, 18), got (%f, %f)\n",res.x, res.y);
    }
    else {
        SUCCESS("Got (%f, %f), as expected\n",res.x,res.y);
    }
}

void testMatrixMultiply() {
    Matrix a = {
        .data = {{2,2},{2,2}}
    };
    Matrix b = {
        .data = {{3,3}, {4, 4}}
    };
    Matrix res = matrixMultiply(a, b);
    if(ds(res.data[0][0], 14) &&
        ds(res.data[0][1], 14) &&
        ds(res.data[1][0], 14) &&
        ds(res.data[1][1], 14)) {
        SUCCESS("Got the proper matrix\n");
    }
    else {
        ERROR("Got an improper matrix\n");
    }
}

void testMatrixToString() {
    Matrix m = {
        .data = {{1, 2}, {3, 4}}
    };
    const char *s = matrixToString(m);
    const char *real = "[[1,2],[3,4]]";
    if(s == NULL) {
        ERROR("Expected a string, got NULL\n");
        return;
    }
    if(strcmp(s, real)) {
        ERROR("Expected '%s', got '%s'\n",real, s);
    }
    else {
        SUCCESS("Got '%s' for matrix, as expected.\n",s);
    }
}

int main() {
    testMatrixMultiply();
    testMatrixTransform();
    testMatrixToString();
}
