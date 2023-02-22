#include "gostrings.h"


int main() {
    const char *words[] = {"Hello ", "world", "!"};
    const char *sep = "";

    char *result = join(words, 3, sep);
    if (result != NULL) {
        printf("%s\n", result); // prints "Hello, world, !"
        free(result);
    }

    return 0;
}