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
//Clone has the unique ability to d
#define MAX_CLONES 1000
#define MAX_LENGTH 100

struct gc_info {
    void *ptr;
};

struct gc_info gc_ptrs[MAX_CLONES];
int num_clones = 0;

void *Clone(const char *str) {
    // Allocate enough memory for the new string
    char* new_str = (char*)malloc((strlen(str) + 1));
    strcpy(new_str, str);


    // Allocate a new gc_info struct and register both the new clone and the original string
    struct gc_info info;
    //printf("Allocating this to: %p\n", new_str);
    info.ptr = new_str;
    gc_ptrs[num_clones++] = info;

    // Return the new string
    return new_str;
}

void clone_collect() {
    // Free all of the cloned strings and original strings
    for (int i = 0; i < num_clones; i++) {
        //printf("Freeing up %p\n", gc_ptrs[i].ptr);
        free(gc_ptrs[i].ptr);
        gc_ptrs[i].ptr = NULL; // Reset the pointer in the gc_info struct
    }

    // Reset the clone and gc_ptrs arrays and count
    num_clones = 0;
}

int compare(char *s1, char *s2) {
  int result = strcmp(s1, s2);
  if (result < 0) {
    return -1;
  } else if (result > 0) {
    return 1;
  } else {
    return 0;
  }
}

char* cut(char *str, char *sep) {
  char *result = malloc(strlen(str) + 1);
  if (result == NULL) {
    fprintf(stderr, "Error: memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  int len_sep = strlen(sep);
  int pos = 0;
  char *token = strtok(str, sep);
  while (token != NULL) {
    int len_token = strlen(token);
    strncpy(result + pos, token, len_token);
    pos += len_token;
    token = strtok(NULL, sep);
    if (token != NULL) {
      strncpy(result + pos, "", len_sep);
      pos += len_sep;
    }
  }
  result[pos] = '\0';
  return result;
}

char* cut_suffix(char *str, char *suffix) {
  int len_str = strlen(str);
  int len_suffix = strlen(suffix);
  if (len_suffix > len_str) {
    return strdup(str);
  }
  if (strncmp(str + len_str - len_suffix, suffix, len_suffix) == 0) {
    char *result = malloc(len_str - len_suffix + 1);
    if (result == NULL) {
      fprintf(stderr, "Error: memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    strncpy(result, str, len_str - len_suffix);
    result[len_str - len_suffix] = '\0';
    return result;
  } else {
    return strdup(str);
  }
}

char* cut_prefix(char *str, char *prefix) {
  int len_str = strlen(str);
  int len_prefix = strlen(prefix);
  if (len_prefix > len_str) {
    return strdup(str);
  }
  if (strncmp(str, prefix, len_prefix) == 0) {
    char *result = malloc(len_str - len_prefix + 1);
    if (result == NULL) {
      fprintf(stderr, "Error: memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    strncpy(result, str + len_prefix, len_str - len_prefix);
    result[len_str - len_prefix] = '\0';
    return result;
  } else {
    return strdup(str);
  }
}

char* trim(char *str, char *chars) {
  int len_str = strlen(str);
  int len_chars = strlen(chars);
  int start = 0;
  int end = len_str - 1;
  while (start <= end && strchr(chars, str[start]) != NULL) {
    start++;
  }
  while (end >= start && strchr(chars, str[end]) != NULL) {
    end--;
  }
  char *result = malloc(end - start + 2);
  if (result == NULL) {
    fprintf(stderr, "Error: memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  strncpy(result, str + start, end - start + 1);
  result[end - start + 1] = '\0';
  return result;
}

char *repeat(char *s, int count) {
    int len = strlen(s);
    int totalLen = len * count;
    char *result = malloc(totalLen + 1);
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < count; i++) {
        memcpy(result + i * len, s, len);
    }
    result[totalLen] = '\0';
    return result;
}

char *replace(char *s, char *old, char *new) {
    char *result = NULL;
    char *p = strstr(s, old);  // find the first occurrence of old in s
    if (p != NULL) {
        int old_len = strlen(old);
        int new_len = strlen(new);
        int prefix_len = p - s;  // length of the prefix before the old substring
        int result_len = prefix_len + new_len + strlen(p + old_len);  // total length of the result string
        result = (char *) malloc((result_len + 1) * sizeof(char));
        if (result != NULL) {
            strncpy(result, s, prefix_len);  // copy the prefix
            strncpy(result + prefix_len, new, new_len);  // copy the new substring
            strncpy(result + prefix_len + new_len, p + old_len, strlen(p + old_len));  // copy the rest of s after the old substring
            result[result_len] = '\0';  // null terminate the string
        }
    }
    return result;
}