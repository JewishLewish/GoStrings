#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//The following functions are designed to be very similiar to Go Lang's functions
//https://pkg.go.dev/strings

//Go Lang's "Split" Function
//"Hello, World" -> "{Hello, World}"
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

//Go Lang's "Fields" Function
//Similiar to Split however it uses Whitespace as a form to split text
//"Hello        world" -> {"Hello", "world"}
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


//replaceall replaces all substrings with a certain string

//      char str[] = "Hello World, World!";
//      const char old[] = "World";
//      const char new[] = "Earth";
//      replaceall(str, old, new);
//      printf("%s\n", str); // prints "Hello Earth, Earth!"

char* replaceall(char *str, const char *old, const char *new) {
    char *p = strstr(str, old);
    while (p != NULL) {
        size_t old_len = strlen(old);
        size_t new_len = strlen(new);
        memmove(p + new_len, p + old_len, strlen(p + old_len) + 1);
        memcpy(p, new, new_len);
        p = strstr(p + new_len, old);
    }
    free(p);
    return str;
}

bool equalFold(const char *s1, const char *s2) {
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    if (s1_len != s2_len) {
        return false;
    }

    for (size_t i = 0; i < s1_len; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return false;
        }
    }

    return true;
}

int go_count(const char *s, const char *substr) {
    int count = 0;
    size_t substr_len = strlen(substr);

    for (const char *p = s; (p = strstr(p, substr)) != NULL; p += substr_len) {
        count++;
    }

    return count;
}

//Similiar to Go Lang "Join" Function
//If you have an array, you can merge it all into a string
//      const char* strings[] = {"apple", "orange", "banana", "grape"};
//      char* result = join_strings(strings, " ");
//      printf("Result: %s\n", result); -> "Result: apple orange banana grape"
char* join(const char** strings, const char* delimiter) {
    size_t num_strings = sizeof(strings)/2;
    
    size_t total_length = 0;
    for (size_t i = 0; i < num_strings; i++) {
        total_length += strlen(strings[i]);
        if (i < num_strings - 1) {
            total_length += strlen(delimiter);
        }
    }
    
    char* result = malloc(total_length + 1);
    if (result == NULL) {
        return NULL;
    }
    
    size_t position = 0;
    for (size_t i = 0; i < num_strings; i++) {
        strcpy(result + position, strings[i]);
        position += strlen(strings[i]);
        if (i < num_strings - 1) {
            strcpy(result + position, delimiter);
            position += strlen(delimiter);
        }
    }
    
    return result;
}

bool contains(const char* str, const char* substr) {
    if (strstr(str, substr) != NULL) {
        return true;
    }
    return false;
}


//Prefix and Suffix
bool has_prefix(const char* str, const char* prefix) {
    size_t prefix_len = strlen(prefix);
    if (strlen(str) < prefix_len) {
        return false;
    }
    return strncmp(str, prefix, prefix_len) == 0;
}

bool has_suffix(const char* str, const char* suffix) {
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    if (str_len < suffix_len) {
        return false;
    }
    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}

//Index
int index_of(char* str, char* substr) {
    char* p = strstr(str, substr);
    if (p == NULL) {
        return -1;
    }
    return p - str;
}

int last_index_of(char* str, char* substr) {
    char* p = strstr(str, substr);
    int last_index = -1;
    while (p != NULL) {
        last_index = p - str;
        p = strstr(p + 1, substr);
    }
    return last_index;
}

//Cloning System

char* Clone(const char* str) {
    size_t len = strlen(str);
    char* clone = malloc(len + 1);
    if (clone == NULL) {
        return NULL;
    }
    strcpy(clone, str);
    return clone;
}