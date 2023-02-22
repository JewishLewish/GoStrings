#include "gostrings.h"

int main() {
    char str[] = "hello world";
    char substr[] = "o";
    printf("Last index of '%s' in '%s': %d\n", "hello world", "o", last_index_of(str, substr));
    return 0;
}