#include <stdio.h>
#include <stdlib.h>

typedef char bool; // do I need this????
#define true 1
#define false 0

struct list_element{
    int value;
    struct list_element * next;
};
typedef struct list_element list_element;

typedef struct{
    list_element * first;
    list_element * last;
} list;

void list_init(list * container){
    container->first = 0;
    container->last = 0;
}
bool list_empty(list * container){
    return 0 == container->first;
}

list_element * list_begin(list * container){
    return container->first;
}
list_element * list_next(list_element * element){
    return element->next;
}

void list_push_back(list * container, int num){

    list_element * new_element = (list_element*) malloc(sizeof(list_element));
    new_element->value = num;
    if(list_empty(container)){
        container->first = new_element;
        container->last = new_element;
    } else {
        container->last->next = new_element;
        container->last = new_element;
    }
    new_element->next = 0;
}

int list_pop_front(list * container){
    int value = container->first->value;
    list_element * temp = container->first;
    container->first = container->first->next;
    free(temp); // is this efficient considering on the memory used?
    // What about list_element * temp pointer? Does it use the memory?
    // Does it frees after the function determinates?
    return value;
}

void print_list(list * container){
    list_element * element;
    for(element = list_begin(container); element; element = list_next(element)){
        printf("%d\n", element->value);
    }
}


int main() {

    list my_list;
    list_init(&my_list);


    int numOfOperations;
    scanf("%d", &numOfOperations);
    int i;
    for(i = 0; i < numOfOperations; i++){
        char operation;
        scanf(" %c", &operation); // without " " (space before %c). ->  signal Segmentation fault
        if(operation == 'E'){
            int input;
            scanf("%d", &input);
            list_push_back(&my_list, input);
        } else {
            printf("%d ", list_pop_front(&my_list));
        }
    }




//    list_push_back(&my_list, 2);
//    list_push_back(&my_list, 5);
//    list_push_back(&my_list, 6);
//    list_push_back(&my_list, 7);
//
//    print_list(&my_list);
//
//    printf("%d\n", list_pop_front(&my_list));
//    printf("%d\n", list_pop_front(&my_list));
//    printf("%d\n", list_pop_front(&my_list));




    return 0;
}