
#ifndef GO_STRINGS_H
#define GO_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char **split(char *str, const char *delim, int *count);

char **split_after(const char *str, const char *sep, int *count);

char **split_after_n(const char *str, const char *sep, int n, int *count);

char **split_n(const char *str, const char *sep, int n, int *count);

char **fields(char *str, int *count);

char* replaceall(char *str, const char *old, const char *new);

bool equalFold(const char *s1, const char *s2);

int go_count(const char *s, const char *substr);

char* join(const char** strings, const char* delimiter);

bool contains(const char* str, const char* substr);

bool has_prefix(const char* str, const char* prefix);

bool has_suffix(const char* str, const char* suffix);

int index_of(char* str, char* substr);

int last_index_of(char* str, char* substr);

struct gc_info {
    void *ptr;
};

extern struct gc_info gc_ptrs[MAX_CLONES];
extern int num_clones;

void *clone(const char *str);
void clone_collect();

int compare(char *s1, char *s2);

char* cut(char *str, char *sep);

char* cut_suffix(char *str, char *suffix);

char* cut_prefix(char *str, char *prefix);

char* trim(char *str, char *chars);

char *repeat(char *s, int count);

char *replace(char *s, char *old, char *new);

char *toLower(char *s);

char *toUpper(char *s);

char *toTitle(char *s)


#endif /* GO_STRINGS_H */