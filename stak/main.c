#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef unsigned short type_t;

typedef struct {
    type_t *li;
    long len;
    long alloc;
} idar_t;

idar_t* init(long initial_size);
int grow(idar_t* T);
type_t push(idar_t* t, type_t val);
type_t pop(idar_t* t);

int main() {
    int numOfOperations;
    char operation[3];
    int integer;
    idar_t* T = init(10);

    scanf("%d", &numOfOperations);

    for(int i = 0; i < numOfOperations; i++){

        scanf("%s", operation);

        switch(operation[1]){
            case 'O':
                printf("%d \n", pop(T));
                break;
            case 'U':
                scanf("%d", &integer);
                push(T, integer);
                break;
        }
    }
    return 0;
}


idar_t* init(long initial_size){
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

type_t push(idar_t* t, type_t val){
    if(t->len > t->alloc-1){
        assert(grow(t) != 0);
    }
    t->li[t->len++] = val;
    return val;
}

type_t pop(idar_t* t){
    assert(t != NULL);
    assert(t->li != NULL);
    t->len--;
    return t->li[t->len];
}