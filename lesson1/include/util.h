#ifndef _UTIL_H
#define _UTIL_H
#include <stdio.h>

/**
 * Copy the string from str1 to str2.
 * Assume the memory pointed to by str2 is large enough to fit str1.
 * Be sure to also write the null terminator.
 */
void copyString(char *str1, char *str2);

// Get the length of a given string, NOT INCLUDING the '\0' at the end
int stringLength(char *str);

// Compares two strings.
// If the strings are equal, return 0.
// If the first char from str1 that does not match is less than the char 
// in str2, return -1
// If the first char from str1 that does not match is greater than the char
// in str2, return 1.
int stringCompare(const char *str1, const char *str2);

#endif
