#include <stdio.h>
#include<malloc.h>
#define SIZE 10000

typedef struct{
    int n;
    int * intarr;
} priorityQueue;

void insert(priorityQueue * pq, int x);
void init(priorityQueue* pq);
void bubbleUp(priorityQueue *pq, int n);

void printQueue(priorityQueue * pq);

int main() {
    priorityQueue pq;
    init(&pq);
//    insert(&pq, 2);
//    insert(&pq, 5);
//    insert(&pq, 7);
//    insert(&pq, 6);
//    insert(&pq, 4);
//
//    printQueue(&pq);


    int numOfOperations;
    char operation;
    int integer;

    scanf("%d", &numOfOperations);

    for(int i = 0; i < numOfOperations; i++){

        scanf(" %c", &operation);

        switch(operation){
            case 'I':
                scanf("%d", &integer);
                insert(&pq, integer);
                break;
            case 'E':
                scanf("%d", &integer);
                printf("%d ", integer);
                break;
            case 'P':
                printQueue(&pq);
                break;
        }
    }
    return 0;
}

void printQueue(priorityQueue * pq) {
    for(int i = 1; i <= pq->n; i++ ){
        printf("%d ", pq->intarr[i]);
    }
    printf("\n");
}

void init(priorityQueue* pq){
    pq->n = 0;
    pq->intarr = (int *) malloc( SIZE * sizeof(int));
}


void insert(priorityQueue * pq, int x){


    pq->n++;
    if(pq->n > SIZE){
        printf("Queue is full!");
        return;
    }

    pq->intarr[pq->n] = x;
    if (pq->n > 1) {
        bubbleUp(pq, pq->n);
    }
}

void bubbleUp(priorityQueue *pq, int n) {

    // find parent index
    int parent = n / 2;
    if(parent < 1){
        return;
    }
    if (pq->intarr[n] > pq->intarr[parent]){
        // swapping parnt and child
        int temp = pq->intarr[parent];
        pq->intarr[parent] = pq->intarr[n];
        pq->intarr[n] = temp;
        //continue with parent
        bubbleUp(pq, parent);
    }
}

