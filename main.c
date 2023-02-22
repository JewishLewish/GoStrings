#include "gostrings.h"


int main() {
    const char* str = "hello world";
    const char* substr = "world";
    if (contains(str, substr)) {
        printf("'%s' contains '%s'\n", str, substr);
    } else {
        printf("'%s' does not contain '%s'\n", str, substr);
    }
    return 0;
}