#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void startError(){
    printf("\x1B[31m");
}

void clearColor() {
    printf("\x1B[0m");
}

void startSuccess(){
    printf("\x1B[0m ✓ ");
}

void testCopyString() {
    const char *str = "This is a test";
    char *str2 = malloc(strlen(str) + 1);
    copyString((char *) str, str2);
    if(strcmp(str, str2)) {
        startError();
        printf("testCopyString: String was not copied! \n");
    }
    else {
        startSuccess();
        printf("testCopyString succcessful");
    }

    clearColor();
}

void testStringLength() {
    const char *str = "this is a test";
    int real = strlen(str);
    int res = stringLength((char*)str);
    if(real != res) {
        startError();
        printf("testStringLength: Expected %i, got %i\n",real,res);
    }
    else {
        startSuccess();
        printf("testStringLength successful");
    }
    clearColor();
}

void testStringCompare() {
    if(stringCompare("aaa", "aaa") != 0) {
        startError();
        printf("testStringCompare: equality comparison failed\n");
    }
    else {
        startSuccess();
        printf("testStringCompare: equality comparison successful\n");
    }
    clearColor();
    if(stringCompare("aaa", "aba") != -1) {
        startError();
        printf("testStringCompare: less than comparison failed\n");
    }
    else {
        startSuccess();
        printf("testStringCompare: less than comparison successful\n");
    }
    clearColor();
    if(stringCompare("aba", "aaa") != 1) {
        startError();
        printf("testStringCompare: greater than comparison failed\n");
    }
    else {
        startSuccess();
        printf("testStringCompare: greater than comparison successful\n");
    }
    clearColor();
}

int main() {
    testCopyString();
    testStringLength();
    testStringCompare();
    return 0;
}
