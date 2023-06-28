
#include <stdio.h>
#include <stdlib.h>

#include "forward_list.h"


int IsEmpty(ForwardList *l){
    return (l->head == NULL && l->last == NULL) ? 1 : 0;
}
int IsEqual(int first, int second){
    return (first == second) ? 1 : 0;
}

/// Reavaliar essa função pois não deixa o código genérico
int IsEqualDataType(data_type first, data_type second){
    return (first == second) ? 1 : 0;
}


Node *node_construct(data_type value, Node *next){
    Node *NewNode = (Node *) malloc(sizeof(Node));
    NewNode->value = value;
    NewNode->next = next;
    return NewNode;
}
void node_destroy(Node *n){
    free(n);
}
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

data_type forward_list_find(ForwardList *l, void *key, int (*cmp_fn)(data_type data, void *key)){
    Node *iterator = l->head;
    while (iterator != NULL)
    {
        if(cmp_fn(iterator->value,key)) return iterator->value;
        iterator = iterator->next;
    }
    printf("Error Forward List Find | Not Exists");
    exit(EXIT_FAILURE);
}

void forward_list_push_front(ForwardList *l, data_type data){
        if(IsEmpty(l)){
            Node *NewNode = node_construct(data,NULL);
            l->head = NewNode;
            l->last = NewNode;
            l->size++;
        }else{
            Node *NewNode = node_construct(data,l->head);
            l->head = NewNode;
            l->size++;
        }
}

void forward_list_push_back(ForwardList *l, data_type data){
          if(IsEmpty(l)){
            Node *NewNode = node_construct(data,NULL);
            l->head = NewNode;
            l->last = NewNode;
            l->size++;
        }else{
            Node *NewNode = node_construct(data,NULL);
            l->last->next = NewNode;
            l->last = NewNode;
            l->size++;
        }
}

void forward_list_print(ForwardList *l, void (*print_fn)(data_type)){
    Node *iterator = l->head;
    while (iterator != NULL)
    {
        print_fn(iterator);
        iterator = iterator->next;
    }
}

data_type forward_list_get(ForwardList *l, int i){
    int counter;
    Node *iterator = l->head;
    if(IsEmpty(l)){
        printf("Forward List Get | Empty List Error\n");
        exit(EXIT_FAILURE);
    }
    while (iterator != NULL)
    {
        if (IsEqual(i,counter))
        {
            return iterator->value;
        }
        iterator = iterator->next;
        counter++;
    }   
}

data_type forward_list_pop_front(ForwardList *l){
    if(IsEmpty(l)){
            printf("Forward List Pop Front | Empty list error\n");
            exit(EXIT_FAILURE);
    }else{
            data_type value = l->head->value;
            Node *iterator = l->head;
            l->head = l->head->next;
            node_destroy(iterator);
            return value;
    }
}

void forward_list_clear(ForwardList *l){
    Node *iterator = l->head;
    while (iterator != NULL)
    {
        l->head = l->head->next;
        node_destroy(iterator);
        iterator = l->head;
    } /// testar pois pode dar merda
}

void forward_list_remove(ForwardList *l, data_type val){
    if (IsEmpty(l))
    {
        printf("Forward List Remove | Empty List Error\n");
        exit(EXIT_FAILURE);
    }else{
        Node *iterator = l->head;
        while (iterator != NULL)
        {
            /// arranjar um jeito de remover elemento do meio
            if(IsEqualDataType(iterator->value, val) || IsEqualDataType(iterator->next->value, val)){
                
            }
        }
    }
}
void forward_list_destroy(ForwardList *l){

}