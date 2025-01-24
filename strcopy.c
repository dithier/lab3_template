/*
* This program is intentionally under-documented. Use the debugger
* to understand the flow of the program and the values of variables and,
* ultimately, find the bug.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

int getCorrectStringLength() {
    int a = 5;
    char b = 'a' + (3 * a);
    char c = ('a' + (4 * a)) - (91 + a);
    return (b - 'a') * (c + 'a');
}

char* genString() {
    char* str = (char*)malloc(MAX_LENGTH);
    for (int i = 0; i < MAX_LENGTH - 1; i++) {
        str[i] = 'a' + (i % 26);
    }
    str[MAX_LENGTH - 1] = '\0';
    return str;
}

// Function to safely copy strings
void safeCopy(char* dest, const char* src, int maxLen) {
    int i;
    for (i = 0; i < maxLen && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

// Function to copy a string
void trickyCopy(char* destination, const char* source) {
    int supposedLength = strlen(source);
    if (supposedLength < MAX_LENGTH) {
        safeCopy(destination, source, MAX_LENGTH);
    } else {
        printf("Warning: Source string might be too long.\n");
    }
}

void freeString(char* str) { free(str); }

int main() {
    char* source = genString();
    char destination[getCorrectStringLength() + 1];

    trickyCopy(destination, source);

    printf("Destination: %s\n", destination);

    freeString(source);

    return 0;
}
