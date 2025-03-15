/* Write the strtok() function. */
#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim) {
    static char *input = NULL;

    if (str != NULL) {
        input = str;
    }
    if (input == NULL || *input == '\0') {
        return NULL;
    }
    char *token_start = input;
    while (*token_start && strchr(delim, *token_start)) {
        token_start++;
    }
    if (*token_start == '\0') {
        input = NULL;
        return NULL;
    }
    input = token_start;
    while (*input && !strchr(delim, *input)) {
        input++;
    }
    if (*input != '\0') {
        *input = '\0';
        input++;
    } else {
        input = NULL;
    }
    return token_start;
}

int main() {
    char str[] = "Hello, world! This is a sample string.";
    char delimiters[] = " ,!.";
    char *token = my_strtok(str, delimiters);
    while (token != NULL) {
        printf("%s\n", token);
        token = my_strtok(NULL, delimiters);
    }

    return 0;
}

