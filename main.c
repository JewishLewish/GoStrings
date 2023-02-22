#include "gostrings.h"


int main() {
    const char* str = "HELLO WORLD";
    char* lowercase_str = toLowerCase(str);
    if (lowercase_str == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    printf("%s\n", lowercase_str);
    free(lowercase_str);
    return 0;
}