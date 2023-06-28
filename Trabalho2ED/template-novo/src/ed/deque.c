
#include "deque.h"
#include <stdlib.h>

#include "forward_list.h"

///--------------------------------------------------------------------------------------------------

typedef struct Dode
{
    data_type value;
    struct Dode *next,*prev;
} Dode;

Dode *Dode_construct(data_type value, Dode *prev,Dode *next){
    Dode *NewDode = (Dode *) malloc(sizeof(Dode));
    NewDode->next = prev;
    NewDode->prev =next;
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
        if(l->head == l->last == NULL){
            Dode *NewDode = Dode_construct(data,NULL, NULL);
            l->head = NewDode;
            l->last = NewDode;
            l->size++;
        }else{
            Dode *NewDode = Dode_construct(data,NULL, l->head);
            l->head->prev = NewDode;
            l->head = NewDode;
            l->size++;
        }
}
void Dorward_list_push_back(DorwardList *l, data_type data){
         if(l->head == l->last == NULL){
            Dode *NewDode = Dode_construct(data,NULL, NULL);
            l->head = NewDode;
            l->last = NewDode;
            l->size++;
        }else{
            Dode *NewDode = Dode_construct(data,l->last,NULL);
            l->last->next = NewDode;
            l->last = NewDode;
            l->size++;
        }
}

data_type Dorward_list_pop_front(DorwardList *l){
        if(l->head == l->last == NULL){
            printf("DL_pop_front ERROR");
            exit(EXIT_FAILURE);
        }else{
            Dode *ToRemove = l->head;
            data_type value = ToRemove->value;
            l->head = l->head->next;
            l->head->prev = NULL;
            Dode_destroy(ToRemove);
            return value;
        }
}
data_type Dorward_list_pop_back(DorwardList *l){
          if(l->head == l->last == NULL){
              printf("DL_pop_back ERROR");
            exit(EXIT_FAILURE);
        }else{
            Dode *ToRemove = l->last;
            data_type value = ToRemove->value;
            l->last = l->last->prev;
            l->last->next = NULL;
            Dode_destroy(ToRemove);
            return value;
        }
}

data_type Dorward_list_get_from_idx(DorwardList *l, int idx){
    int counter = 1;
    Dode *iterator = l->head;

    if(idx > l->size || idx < 0){
        printf("Dorward LIST Get from IDX | Index Error");
        exit(EXIT_FAILURE);
    }
    while(iterator != NULL){
        if(counter == idx){
            return iterator->value;
        }else{
            iterator = iterator->next;
            counter++;
        }
    }
}

////-------------------------------------------------------------------------------------------------

struct Deque{
    DorwardList *deque;
    data_type buffer;
};

Deque *deque_construct(void){
    Deque *NewDeque = (Deque *) malloc(sizeof(Deque));
    return NewDeque;
}

// funcoes para insercao na direita e esquerda (devem ser feitas em O(1), com eventual realloc)
void deque_push_back(Deque *d, void *val){
    Dorward_list_push_back(d->deque,val);
}
void deque_push_front(Deque *d, void *val){
    Dorward_list_push_front(d->deque,val);
}


// funcoes para remocao na direita e esquerda (devem ser feitas em O(1))
void *deque_pop_back(Deque *d){
    d->buffer = Dorward_list_pop_back(d->deque);
}
void *deque_pop_front(Deque *d){
    d->buffer = Dorward_list_pop_front(d->deque);
}

// numero de elementos
int deque_size(Deque *d){
    return d->deque->size;
}

// obtem o i-esimo elemento
void *deque_get(Deque *d, int idx){
    d->buffer = Dorward_list_get_from_idx(d->deque,idx);
}

// libera o espaco alocado para o deque
void deque_destroy(Deque *d){
    DorwardList_destroy(d->deque);
}


// TODO!