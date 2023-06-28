#include "deque.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Deque *NovoDeque = deque_construct();
    deque_push_front(NovoDeque,10);
    deque_pop_front(NovoDeque);
    deque_destroy(NovoDeque);
    return 0;
}