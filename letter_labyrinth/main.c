#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000  //size of queue

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node
{
    int vertex;
    struct node* next;
    int distance;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
int bfs(struct Graph* graph, int startVertex, int endVertex);
void printGraph(struct Graph* graph);

/* Breadth First Search
 * Returns distance from start vertex to end vertex
 */
int bfs(struct Graph* graph, int startVertex, int endVertex) {
    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    graph->adjLists[startVertex]->distance = 0;

    while(!isEmpty(q)){
        int currentVertex = dequeue(q);
        struct node* temp = graph->adjLists[currentVertex];
        int currentDistance = graph->adjLists[currentVertex]->distance;

        while(temp) {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){

                graph->adjLists[adjVertex]->distance = currentDistance + 1;
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    return graph->adjLists[endVertex]->distance+1;
}

struct Graph* givenMatrixReturnGraf(char* matrix, int N){

    struct Graph* graph = createGraph(N*N);

    /*############################################
     * Upper left corner
     * ###########################################
     */
    if(*(matrix) != *(matrix+1)){  //on the right
        addEdge(graph,0,1);
    }
    if(*(matrix) != *(matrix+N)){ // lower
        addEdge(graph, 0, N);
    }
    /*############################################
     * Upper right corner
     * ###########################################
     */
    if(*(matrix+N-2) != *(matrix+N-1)){ // on the left
        addEdge(graph, N-2, N-1);
    }
    if(*(matrix+N-1) != *(matrix+(N*2-1))){ // lower
        addEdge(graph, N-1, N*2-1);
    }
    /*############################################
     * Lower left corner
     * ###########################################
     */
    if(*(matrix+(N*(N-1))) != *(matrix+(N*(N-2)))){ //upper
        addEdge(graph, N*(N-1), N*(N-2));
    }
    if(*(matrix+(N*(N-1))) != *(matrix+(N*(N-1)+1))){ //on the right
        addEdge(graph, N*(N-1), N*(N-1)+1);
    }
    /*############################################
     * Lower right corner
     * ###########################################
     */
    if(*(matrix+(N*N-1)) != *(matrix+(N*(N-1)-1))) { // upper
        addEdge(graph,N*N-1, N*(N-1)-1);
    }
    if(*(matrix+(N*N-1)) != *(matrix+(N*N-2))) {
        addEdge(graph, N*N-1, N*N-2);
    }
    /*###########################################
     *  Left border
     * ##########################################
     */
    for(int i = 1; i < N-2; i++){
        if(*(matrix+i*N) != *(matrix+(i+1)*N)){
            addEdge(graph, i*N, (i+1)*N);
        }
    }
    /*##########################################
     * Upper border
     * #########################################
     */
    for(int i = 1; i < N-2; i++){
        if(*(matrix+i) != *(matrix+i+1)){
            addEdge(graph, i, i+1);
        }
    }
    /*##########################################
     * Right border
     * #########################################
     */
    for(int i = 2; i<N-1; i++){
        if(*(matrix+i*N-1) != *(matrix+(i+1)*N-1)){
            addEdge(graph, i*N-1, (i+1)*N-1);
        }
    }
    /*##########################################
     * Lower border
     * #########################################
     */
    for(int i = 1; i<N-2; i++){
        if(*(matrix+N*(N-1)+i) != *(matrix+N*(N-1)+i+1)){
            addEdge(graph, N*(N-1)+i, N*(N-1)+i+1);
        }
    }
    /*############################################
     * Inner elements
     * ###########################################
     */
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j< N-1; j++){

            if(*(matrix+i*N+j) != *(matrix+(i-1)*N+j)){ // upper
                addEdge(graph, i*N+j, (i-1)*N+j);
            }
            if(*(matrix+i*N+j) != *(matrix+(i*N)+j-1)){ // left
                addEdge(graph, i*N+j, (i*N)+j-1);
            }
            if(*(matrix+i*N+j) != *(matrix+i*N+j+1)){  // right
                addEdge(graph, i*N+j, i*N+j+1);
            }
            if(*(matrix+i*N+j) != *(matrix+(i+1)*N+j)){ // lower
                addEdge(graph, i*N+j, (i+1)*N+j);
            }
        }
    }
    return graph;
}


int main()
{
    // make 2d array
    // concert array to adjacency list
    // kør BFS på den bfs)graph, 0,n*n-1

    int N;
    scanf("%d", &N);
    char matrix[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char letter;
            scanf(" %c", &letter);
            matrix[i][j] = letter;
        }
    }
    struct Graph* graph = givenMatrixReturnGraf(&matrix[0][0], N);

 //   printGraph(graph);
    printf("%d", bfs(graph, 0, N*N-1));

    return 0;
}







struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->rear == SIZE-1) {
            printf("\nQueue is Full!!");
    }
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            //  printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}