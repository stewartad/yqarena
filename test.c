#include "src/yqarena.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

struct test_struct
{
    char str[256];
    int64_t num;
};

int main(int argc, char *argv[])
{
    yqarena_t *arena = yqarena_alloc();
    struct test_struct *t = yqarena_push(arena, sizeof(struct test_struct));
    t->num = 25;
    printf("%ld\n", t->num);
    strncpy(t->str, "hello world", 13);

    printf("%s\n", t->str);
    printf("%ld\n", t->num);
    yqarena_pop(arena, sizeof(struct test_struct));

    char *p = yqarena_push(arena, 5);
    strncpy(p, "beep", 5);
    printf("%s\n", t->str);
    printf("%s\n", p);


    return 0;
}
