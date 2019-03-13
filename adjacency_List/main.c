#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
char* isNeighbors(struct Graph* graph, int v1, int v2);

void printNeigh(struct Graph *pGraph, int i);

int main()
{
// just practicing chars, strings
//    char* test;
//    test = "Testing";
//    printf("%s\n", test);
//    printf("%c", test[6]);   //works with *(test+6) too



    int numOfVertices;
    scanf("%d", &numOfVertices);
    struct Graph* graph = createGraph(numOfVertices);

    int numOfEdges;
    scanf("%d", &numOfEdges);

    for(int i = 0; i < numOfEdges; i++){
        int src;
        int des;
        scanf("%d %d", &src, &des);
        addEdge(graph, src, des);
    }

    int numNeighQ;
    scanf("%d", &numNeighQ);
    for(int i=0; i<numNeighQ; i++){
        int v1;
        int v2;
        scanf("%d %d", &v1, &v2);
        printf("%s\n", isNeighbors(graph, v1, v2));
    }

    int numPrintNeighQ;
    scanf("%d", &numPrintNeighQ);
    for(int i=0; i<numPrintNeighQ; i++){
        int v;
        scanf("%d",&v);
        printNeigh(graph, v);
    }
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

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

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

char* isNeighbors(struct Graph* graph, int v1, int v2){
    struct node* temp = graph->adjLists[v1];
    while (temp){
        if(temp->vertex == v2){
            return "YES";
        }
        temp = temp->next;
    }
    return "NO";

}

void printNeigh(struct Graph* graph, int i) {
    struct node* temp = graph->adjLists[i];
    while(temp){
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
}
