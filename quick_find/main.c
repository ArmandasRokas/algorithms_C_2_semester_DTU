#include <stdio.h>
#include<malloc.h>

int numOfSets;
int * init();
void union_quick_find(int * array, int i, int j);
int find(int * array, int i);

int main() {

    int * array = init(); // Why it does not work only by sending array reference to init() function

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
                union_quick_find(array, i, j);
        }
    }
    return 0;
}
/************************************
 Initializing an array for quick find
 ***********************************/
int * init(){
    scanf("%d", &numOfSets);
    int * array = (int *) malloc(numOfSets * sizeof(int));
    for(int i = 0; i < numOfSets; i++){
        array[i] = i;
    }
    return array;
}
/***********************************
 Perform union
 ***********************************/
void union_quick_find(int * array, int i, int j){
    int iID = find(array, i);
    int jID = find(array, j);
    if (iID != jID){
        for(int k = 0; k < numOfSets; k++){
            if(array[k] == iID){
                array[k] = jID;
            }
        }
    }
}
/***********************************
 Find representative
 ***********************************/
int find(int * array, int i){
    return array[i];
}