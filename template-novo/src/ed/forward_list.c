
#include <stdio.h>
#include <stdlib.h>

#include "forward_list.h"

// TODO!


typedef struct Node
{
    data_type value;
    struct Node *next;
} Node;

Node *node_construct(data_type value, Node *next){
    Node *NewNode = (Node *) malloc(sizeof(Node));
    NewNode->value = value;
    NewNode->next = next;
    return NewNode;
}
void node_destroy(Node *n){
    free(n);
}

typedef struct
{
    Node *head;
    Node *last;
    int size;
} ForwardList;


ForwardList *forward_list_construct(){
    ForwardList *NewList = (ForwardList *) malloc(sizeof(ForwardList));
    NewList->head = NULL;
    NewList->last = NULL;
    NewList->size = 0;
    return NewList;
}

int forward_list_size(ForwardList *l){
    return l->size;
}

data_type forward_list_find(ForwardList *l, void *key, int (*cmp_fn)(data_type data, void *key));

void forward_list_push_front(ForwardList *l, data_type data);

void forward_list_push_back(ForwardList *l, data_type data);

void forward_list_print(ForwardList *l, void (*print_fn)(data_type));

data_type forward_list_get(ForwardList *l, int i);

data_type forward_list_pop_front(ForwardList *l);

ForwardList *forward_list_reverse(ForwardList *l);

void forward_list_clear(ForwardList *l);

void forward_list_remove(ForwardList *l, data_type val,int (*cmpFn)(data_type, data_type)){
    Node *iterator = l->head;
    Node *last = NULL;
    int cycle = 0;
    while (iterator != NULL)
    {
       
        iterator = iterator->next;
        cycle++;
    }
    
}

void forward_list_destroy(ForwardList *l);

