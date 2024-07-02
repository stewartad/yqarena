#include "yqarena.h"
#include <stdint.h>
#include <stdlib.h>

#define YQARENA_SIZE YQARENA_SIZE_SM
#define YQARENA_SIZE_SM 4096
#define YQARENA_SIZE_MD 8192
#define YQARENA_SIZE_LG 16384
#define YQARENA_SIZE_XL 32768

yqarena_t *yqarena_alloc()
{
    yqarena_t *arena = malloc(sizeof(yqarena_t));
    if (!arena)
    {
        return NULL;
    }
    arena->mem = malloc(sizeof(char) * YQARENA_SIZE);
    if (!arena->mem)
    {
        return NULL;
    }
    arena->size = YQARENA_SIZE;
    return arena;
}

void yqarena_free(yqarena_t *arena)
{
    free(arena->mem);
    free(arena);
}

void *yqarena_push(yqarena_t *arena, int64_t size)
{
    if (arena->pos + size > arena->size)
        exit(1);
    char *p = arena->mem + arena->pos;
    arena->pos += size;
    return (void *)p;
}

void *yqarena_push_zero(yqarena_t *arena, int64_t size)
{
    if (arena->pos + size > arena->size)
        exit(1);
    char *p = arena->mem + arena->pos;
    arena->pos += size;
    char *q = p;
    while (q < p + size)
    {
        *q = 0;
        q++;
    }
    return (void *)p;
}

void yqarena_pop(yqarena_t *arena, int64_t size)
{
    arena->pos -= size;
}
