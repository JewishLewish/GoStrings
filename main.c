#include "gostrings.h"


int main() {
    char str[] = "hello world";
    char substr[] = "world";
    int index = go_index(str, substr);
    printf("Index of '%s' in '%s': %d\n", substr, str, index);
    return 0;
}