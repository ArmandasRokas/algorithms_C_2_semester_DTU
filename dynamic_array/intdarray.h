#include <stdlib.h>

typedef int type_t;

typedef struct {
    type_t *li;
    size_t len;
    size_t alloc;
} idar_t;

idar_t* init(size_t initial_size);
void destroy(idar_t* T);
int grow(idar_t* T);
