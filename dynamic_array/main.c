#include <stdio.h>
#include "intdarray.c"


int main(){
    idar_t* T = init(2);
    print(T);
    append(T,0);
    append(T,1);
    append(T,2);
    append(T,3);
    append(T,4);
    print(T);
}


