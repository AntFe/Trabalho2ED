
#include "deque.h"
#include <stdlib.h>

#include "forward_list.h"
struct Deque{

};
///--------------------------------------------------------------------------------------------------

typedef struct Dode
{
    data_type value;
    struct Dode *next,*prev;
} Dode;

Dode *Dode_construct(data_type value, Dode *next){
    Dode *NewDode = (Dode *) malloc(sizeof(Dode));
    NewDode->next = NULL;
    NewDode->prev =NULL;
    NewDode->value = value;
    return NewDode;
}
void Dode_destroy(Dode *n){
    free(n);
}

typedef struct
{
    Dode *head;
    Dode *last;
    int size;
} DorwardList;

DorwardList *DorwardList_construct(){
    DorwardList *NewDList = (DorwardList *) malloc(sizeof(DorwardList));
    NewDList->head = NULL;
    NewDList->last = NULL;
    NewDList->size = 0;
    return NewDList;
}

void DorwardList_destroy(DorwardList *DList){
    Dode *dode = DList->head;
    DList->last = NULL;

    while (dode != NULL)
    {
        DList->head = DList->head->next;
        Dode_destroy(dode);
        dode = DList->head;
    }
    free(DList);
}

void Dorward_list_push_front(DorwardList *l, data_type data){

}
void Dorward_list_push_back(DorwardList *l, data_type data){
    
}

data_type Dorward_list_pop_front(DorwardList *l){

}
data_type Dorward_list_pop_back(DorwardList *l){

}




////-------------------------------------------------------------------------------------------------
Deque *deque_construct(void){

}

// funcoes para insercao na direita e esquerda (devem ser feitas em O(1), com eventual realloc)
void deque_push_back(Deque *d, void *val){

}
void deque_push_front(Deque *d, void *val){

}


// funcoes para remocao na direita e esquerda (devem ser feitas em O(1))
void *deque_pop_back(Deque *d){

}
void *deque_pop_front(Deque *d){

}

// numero de elementos
int deque_size(Deque *d){

}

// obtem o i-esimo elemento
void *deque_get(Deque *d, int idx){

}

// libera o espaco alocado para o deque
void deque_destroy(Deque *d){

}


// TODO!