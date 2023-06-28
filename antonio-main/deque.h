
#ifndef _DEQUE_H_
#define _DEQUE_H_

typedef int data_type;
typedef struct Deque Deque;

// criacao do deque
Deque *deque_construct(void);

// funcoes para insercao na direita e esquerda (devem ser feitas em O(1), com eventual realloc)
void deque_push_back(Deque *d, data_type val);
void deque_push_front(Deque *d, data_type val);

// funcoes para remocao na direita e esquerda (devem ser feitas em O(1))
void *deque_pop_back(Deque *d);
void *deque_pop_front(Deque *d);

// numero de elementos
int deque_size(Deque *d);

// obtem o i-esimo elemento
void *deque_get(Deque *d, int idx);

// libera o espaco alocado para o deque
void deque_destroy(Deque *d);

void deque_print(Deque *d);

#endif