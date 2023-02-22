#include "gostrings.h"


int main() {
    const char *words[] = {"Hello ", "world", "!"};


    char *result = join(words, 3, "");
    if (result != NULL) {
        printf("%s\n", result); // prints "Hello, world, !"
        free(result);
    }

    return 0;
}