#ifndef YQARENA_H
#define YQARENA_H

#include <stdint.h>
typedef struct {
    char *mem;
    int64_t size;
    int64_t pos;
} yqarena_t;

yqarena_t *yqarena_alloc(void);
void yqarena_free(yqarena_t*);

void *yqarena_push(yqarena_t*, int64_t);
void *yqarena_push_zero(yqarena_t*, int64_t);
void yqarena_pop(yqarena_t*, int64_t);

#endif
