#include <stdio.h>
#include<stdio.h>
#include<malloc.h>
void insert();
void del();
void display();

struct node
{
    int priority;
    int info;
    struct node *next;
}*start=NULL,*q,*temp,*new;

typedef struct node N;


int main() {
    int numOfOperations;
    char operation;
    int integer;

    scanf("%d", &numOfOperations);

    for(int i = 0; i < numOfOperations; i++){

        scanf("%c", &operation);

        switch(operation){
            case 'I':
                scanf("%d", &integer);
                break;
            case 'E':
                scanf("%d", &integer);
                printf("%d", 3);
                break;
            case 'P':
                // print
                printf("%d", 5);
                break;
        }
    }

    return 0;
}



void insert()
{
    int item,itprio;
    new=(N*)malloc(sizeof(N));
//    printf("ENTER THE ELT.TO BE INSERTED :\t");
    scanf("%d",&item);
//    printf("ENTER ITS PRIORITY :\t");
    scanf("%d",&itprio);
    new->info=item;
    new->priority=itprio;
    new->next=NULL;
    if(start==NULL )
    {
//new->next=start;
        start=new;
    }
    else if(start!=NULL&&itprio<=start->priority)
    {  new->next=start;
        start=new;
    }
    else
    {
        q=start;
        while(q->next != NULL && q->next->priority<=itprio)
        {q=q->next;}
        new->next=q->next;
        q->next=new;
    }
}

void del()
{
    if(start==NULL)
    {
        printf("\nQUEUE UNDERFLOW\n");

    }
    else
    {
        new=start;
        printf("\nDELETED ITEM IS %d\n",new->info);
        start=start->next;
//free(start);
    }
}

void display()
{
    temp=start;
    if(start==NULL)
        printf("QUEUE IS EMPTY\n");
    else
    {
        printf("QUEUE IS:\n");
        if(temp!=NULL)
            for(temp=start;temp!=NULL;temp=temp->next)
            {
                printf("\n%d priority =%d\n",temp->info,temp->priority);
//temp=temp->next;
            }
    }
}


