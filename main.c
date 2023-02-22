#include "gostrings.h"

int main() {
    char str[] = "hello world";
    char substr[] = "o";
    int index = last_index_of(str, substr);
    printf("Last index of '%s' in '%s': %d\n", substr, str, index);
    return 0;
}