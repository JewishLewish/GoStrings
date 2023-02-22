#include "gostrings.c"

int main() {
    char str[] = "hello       world";
    int count = 0;

    char **result = fields(str, &count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
