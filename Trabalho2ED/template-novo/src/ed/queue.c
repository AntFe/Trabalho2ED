
#include "queue.h"
#include "forward_list.h"

struct Queue
{
    ForwardList *queue;
    data_type buffer;
};

Queue *queue_construct(){
    Queue *NewQueue = (Queue *) malloc(sizeof(Queue));
    NewQueue->queue = forward_list_construct();
    return NewQueue;
}
void queue_push(Queue *queue, void *data){
    forward_list_push_back(queue->queue,(data_type *) &data);
}
bool queue_empty(Queue *queue){
    int size = forward_list_size(queue->queue);
    return (size == 0) ? 1 : 0;
}
void *queue_pop(Queue *queue){
    queue->buffer = forward_list_pop_front(queue->queue);
}
void queue_destroy(Queue *queue){
    forward_list_destroy(queue->queue);
    free(queue);
}



// TODO!