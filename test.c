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

int main() {
    testCopyString();
    return 0;
}
