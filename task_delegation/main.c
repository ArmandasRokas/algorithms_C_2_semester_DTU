#include <stdio.h>
#include <malloc.h>
#define SIZE 1000000

typedef struct{
    int id;
    int difficulty;
} task;

typedef struct{
    int n;
    task * tasks;
} priorityQueue;

void init(priorityQueue* pq);
void bubbleUp(priorityQueue *pq, int n);
void insert(priorityQueue * pq, int id, int difficulty);
void printQueue(priorityQueue * pq);
void bubbleDown(priorityQueue *pq, int n);
int extractMax(priorityQueue *pq);


int main() {
    priorityQueue pq; // hvor meget allocere det?
    init(&pq);

    int numOfInput, index, difficulty;
    scanf("%d", &numOfInput);

    for(int i = 0; i < numOfInput; i++){
        char input;
        scanf(" %c", &input);
        switch (input){
            case 'N':
                scanf("%d %d", &index, &difficulty);
                insert(&pq, index, difficulty);
                break;
            case 'R':
                printf("%d\n", extractMax(&pq));
                break;
        }
    }
    return 0;
}

void init(priorityQueue* pq){
    pq->n = 0;
    pq->tasks = (task *) malloc( SIZE * sizeof(task));
}

void printQueue(priorityQueue * pq) {
    for(int i = 1; i <= pq->n; i++ ){
        printf("Id: %d, difficulty: %d \n", pq->tasks[i].id, pq->tasks[i].difficulty);
    }
    printf("\n");
}

void insert(priorityQueue * pq, int id, int difficulty){
    pq->n++;
    if(pq->n > SIZE){
        printf("Queue is full!");
        return;
    }
   // task * newTask = (task *) malloc(sizeof(task));
   // newTask->id = id;
   // newTask->difficulty = difficulty;
   // pq->tasks[pq->n] = *newTask;
    pq->tasks[pq->n].id = id;
    pq->tasks[pq->n].difficulty = difficulty;
    if (pq->n > 1) {
        bubbleUp(pq, pq->n);
    }
}

void bubbleUp(priorityQueue *pq, int n) {
    // find parent index
    int parent = n / 2;
    if (parent < 1) {
        return;
    }
    if (pq->tasks[n].difficulty > pq->tasks[parent].difficulty) {
        // swapping parent and child
        task * temp =(task *) malloc (sizeof(task));
        *temp = pq->tasks[parent];
        pq->tasks[parent] = pq->tasks[n];
        pq->tasks[n] = *temp;
        free(temp); // test uden den.
        bubbleUp(pq, parent);
    }
}
//  returns an id of a task
int extractMax(priorityQueue *pq) {
    int r = pq->tasks[1].id;
  //  free(&pq->tasks[1]);  // skal der ikke være nogen free her? Jeg tror ikke, så vi fjere en plads fra listen, som kan ikke bruger mere.
    pq->tasks[1] = pq->tasks[pq->n];
    pq->n--;
    bubbleDown(pq, 1);
    return r;
}

void bubbleDown(priorityQueue *pq, int n) {
    int leftChild =  2*n;
    int rightChild = 2*n+1;
    int largest;
    if(pq->tasks[leftChild].difficulty > pq->tasks[n].difficulty && leftChild <= pq->n){
        largest = leftChild;
    } else {
        largest = n;
    }
    if(pq->tasks[rightChild].difficulty > pq->tasks[largest].difficulty && rightChild <= pq->n ){
        largest = rightChild;
    }
    if(largest != n){
        task * temp =(task *) malloc (sizeof(task));
        *temp = pq->tasks[n];
        pq->tasks[n] = pq->tasks[largest];

        pq->tasks[largest] = *temp;
        free(temp);

        bubbleDown(pq, largest);
    }
}