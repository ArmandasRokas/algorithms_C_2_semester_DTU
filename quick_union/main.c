#include <stdio.h>
#include<malloc.h>


int * init(int numOfSets);
void quick_union(int * array, int * treeSizes, int i, int j);
int find(int * array, int i);
int *init_treeSizes(int numOfSets);

int main() {

    int numOfSets;
    scanf("%d", &numOfSets);
    int * array = init(numOfSets); // Why it does not work only by sending array reference to init() function
    int * treeSizes = init_treeSizes(numOfSets);

    int numOfOperations;
    scanf("%d", &numOfOperations);

    for(int i = 0 ; i < numOfOperations; i++){
        char operation;
        scanf(" %c", &operation);
        int x;
        int i;
        int j;

        switch (operation){
            case 'F' :
                scanf("%d", &x);
                printf("%d\n", find(array, x));
                break;
            case 'U' :
                scanf("%d %d", &i ,&j);
                quick_union(array,treeSizes, i, j);
        }
    }
    return 0;
}
/**********************
 Initializing treeSizes array
 **********************/
int * init_treeSizes(int numOfSets) {
    int * treeSizes = (int *) malloc(numOfSets * sizeof(int)); // complains if  = {0}. Why?
    for(int i = 0; i < numOfSets; i++){
        treeSizes[i] = 1;
    }
    return treeSizes;
}

/************************************
 Initializing an array for quick find
 ***********************************/
int * init(int numOfSets){
    int * array = (int *) malloc(numOfSets * sizeof(int));
    for(int i = 0; i < numOfSets; i++){
        array[i] = i;
    }
    return array;
}
/***********************************
 Perform weighted quick union
 ***********************************/
void quick_union(int * array, int * treeSizes, int i, int j){
    int r_i = find(array, i);
    int r_j = find(array, j);
    if (r_i != r_j){
        if(treeSizes[r_i] < treeSizes[r_j]){
            array[r_i] = r_j;
            treeSizes[r_j] = treeSizes[r_i] + treeSizes[r_j];
        } else {
            array[r_j] = r_i;
            treeSizes[r_i] = treeSizes[r_i] + treeSizes[r_j];
        }
    }
}
/***********************************
 Find the root of the i and compress the path. Returns the same i if the i is the root
 ***********************************/
int find(int * array, int i){
    // ######### Without path compression ##########
//    while(i != array[i]){
//        i = array[i];
//    }
// ################################################

    if(i != array[i]){
        array[i] = find(array, array[i]);
    }
    return array[i];
}