#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *str, const char *delim, int *count) {
    char **result = NULL;
    char *token = strtok(str, delim);

    *count = 0;
    while (token != NULL) {
        result = realloc(result, (*count + 1) * sizeof(char *));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, delim);
    }
    free(token);

    return result;
}

char **fields(char *str, int *count) {
    char **result = NULL;
    char *token = strtok(str, " \t\n\r\f\v");

    *count = 0;
    while (token != NULL) {
        result = realloc(result, (*count + 1) * sizeof(char *));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, " \t\n\r\f\v");
    }
    free(token);

    return result;
}

int main() {
    char str[] = "hello       world";
    int count = 0;

    char **result = fields(str, &count);

    for (int i = 0; i < count; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
