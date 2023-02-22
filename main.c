#include "gostrings.h"


int main() {
    const char* str = "hello world";
    const char* suffix = "world";
    if (has_suffix(str, suffix)) {
        printf("'%s' has suffix '%s'\n", str, suffix);
    } else {
        printf("'%s' does not have suffix '%s'\n", str, suffix);
    }
    return 0;
}