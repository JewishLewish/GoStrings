#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char* replaceall(char *str, const char *old, const char *new) {
    char *p = strstr(str, old);
    while (p != NULL) {
        size_t old_len = strlen(old);
        size_t new_len = strlen(new);
        memmove(p + new_len, p + old_len, strlen(p + old_len) + 1);
        memcpy(p, new, new_len);
        p = strstr(p + new_len, old);
    }
    return str;
}

int equalFold(const char *s1, const char *s2) {
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    if (s1_len != s2_len) {
        return 0;
    }

    for (size_t i = 0; i < s1_len; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return 0;
        }
    }

    return 1;
}

int go_count(const char *s, const char *substr) {
    int count = 0;
    size_t substr_len = strlen(substr);

    for (const char *p = s; (p = strstr(p, substr)) != NULL; p += substr_len) {
        count++;
    }

    return count;
}

char *join(const char **s, int n, const char *sep) {
    if (n <= 0) {
        return NULL;
    }

    // calculate the total length of the joined string
    int sep_len = strlen(sep);
    int len = strlen(s[0]);
    for (int i = 1; i < n; i++) {
        len += sep_len + strlen(s[i]);
    }

    // allocate memory for the joined string
    char *result = (char *) malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }

    // copy the first element
    strcpy(result, s[0]);

    // concatenate the remaining elements with the separator
    for (int i = 1; i < n; i++) {
        strcat(result, sep);
        strcat(result, s[i]);
    }

    return result;
}