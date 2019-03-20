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
int extractMax(priorityQueue *pq);
void bubbleDown(priorityQueue *pq, int n);

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
                printf("%d\n", extractMax(&pq));
                break;
            case 'P':
                printQueue(&pq);
                break;
        }
    }
    return 0;
}

int extractMax(priorityQueue *pq) {
    int r = pq->intarr[1];
    pq->intarr[1] = pq->intarr[pq->n];
    pq->n--;
    bubbleDown(pq, 1);
    return r;
}

void bubbleDown(priorityQueue *pq, int n) {
    int leftChild =  2*n;
    int rightChild = 2*n+1;
    int largest;
    if(pq->intarr[leftChild] > pq->intarr[n] && leftChild <= pq->n){
        largest = leftChild;
    } else {
        largest = n;
    }
    if(pq->intarr[rightChild] > pq->intarr[largest] && rightChild <= pq->n ){
        largest = rightChild;
    }
    if(largest != n){
        int temp = pq->intarr[n];
        pq->intarr[n] = pq->intarr[largest];
        pq->intarr[largest] = temp;
        bubbleDown(pq, largest);
    }
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



