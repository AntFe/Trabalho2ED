
#include "queue.h"
#include "stack.h"
#include "forward_list.h"


struct Stack
{
    ForwardList *stack;
    data_type buffer;
};

Stack *stack_construct(){
    Stack *NewStack = (Stack *) malloc(sizeof(Stack));
    NewStack->stack = forward_list_construct();
    return NewStack;
}
void stack_push(Stack *stack, void *data){
    forward_list_push_front(stack->stack,(data_type *) &data);
}
bool stack_empty(Stack *stack){
    /// como retornar unsigned char???
}
void *stack_pop(Stack *stack){
    stack->buffer = forward_list_pop_front(stack->stack);
}
void stack_destroy(Stack *stack){
    forward_list_destroy(stack->stack);
    free(stack);
}
// TODO!