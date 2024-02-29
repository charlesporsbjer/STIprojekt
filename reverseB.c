#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    char* rev = strrev(str);
    printf("Reversed string: %s\n", rev);
    return 0;
}

char* strrev(char* str) {
    int len = strlen(str);
    char* rev = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        rev[i]