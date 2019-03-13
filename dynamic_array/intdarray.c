//
// Created by Armandas on 3/13/2019.
//

#include <assert.h>
#include "intdarray.h"
#include <string.h>
#include <stdio.h>

 idar_t* init(size_t initial_size){
    idar_t *t = malloc(sizeof(idar_t));
    t->li = malloc(sizeof(int)*initial_size);
    t->alloc = initial_size;
    t->len = 0;
    return t;
}


int grow(idar_t* t){
    assert(t != NULL);
    assert(t->li != NULL);
    type_t* newli = malloc(2*t->alloc);
    if(newli==NULL)
        return 0; // failure to allocate
    memcpy(newli, t->li,sizeof(type_t)*t->len);
    free(t->li);
    t->li = newli;
    t->alloc *= 2;
    return 1; //success
}

void destroy(idar_t* t){
    free(t->li);
    free(t);
}
type_t append(idar_t* t, type_t val){
    if(t->len > t->alloc-1){
        assert(grow(t) != 0);
    }
    t ->li[t->len++] = val;
    return val;
}

void print(idar_t* t){
    assert(t != NULL);
    assert(t->li != NULL);
    printf("len = %d, alloc = %d \n", t->len, t->alloc);
    int i = 0;
    for(i = 0; i < t->len; i++){
        printf("%x \n", t->li[i]); // can be written also like this *(t->li+i)
    }
    puts("");
}
