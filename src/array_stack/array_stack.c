#include "array_stack.h"
/**
 * this work just for create a array stack
 */
array_stack* create_array_stack(int data_size, int stack_size){
    array_stack* stack = malloc(sizeof(array_stack));
    ERR(1, NULL == stack, goto err, "create the array stack fail.\n");

    stack->size = data_size;
    stack->max_size_stack = stack_size;
    stack->count = 0;
    /**
     * some time I confused with the malloc argument was zero,
     * it also can malloc success, I don't know why, but I accept it
     * as know.
     */
    stack->datap = malloc(stack->size*stack->count);
    ERR(1, NULL == stack->datap, goto err1, "create the array stack data fail.\n");

    return stack;
err1:
    free(stack);
err:
    return NULL;
}
/**
 * push the data to the array stack
 */
int push_array_stack(void* data, array_stack* stack){
    if(!is_full_array_stack(stack)){
        void* new_data = malloc(stack->size*(stack->count+1));
        ERR(1, NULL == new_data, return -1, "push array stack malloc data space fail.\n");

        memcpy(new_data, stack->datap, stack->size*stack->count);
        memcpy(new_data+stack->size*stack->count, data, stack->size);

        free(stack->datap);
        stack->datap = new_data;
        stack->count++;
        return 0;
    }
    return -1;
}
void print_array_stack(array_stack* stack, array_stack_print func){
    int i = 0;
    for(; i < stack->count; i++){
        func(stack->datap+stack->size*i);
    }
}
/**
 * pop the data out of the array stack
 */
int pop_array_stack(void* data, array_stack* stack){
    void* new_data = NULL;
    if(!is_empty_array_stack(stack)){
        new_data = malloc(stack->size*(stack->count-1));
        ERR(1, NULL == new_data, goto err, "pop array stack malloc data space fail.\n");

        memcpy(new_data, stack->datap, stack->size*(stack->count-1));
        memcpy(data, stack->datap+stack->size*(stack->count-1), stack->size);

        free(stack->datap);
        stack->datap = new_data;
        stack->count--;

        return 0;
    }else{
        bzero(data, stack->size);
        return -1;
    }
err1:
    free(new_data);
err:
    return -1;
}
/**
 * get the data at the top of array stack
 */
int top_array_stack(void* data, array_stack* stack){
    if(!is_empty_array_stack(stack)){
        memcpy(data, stack->datap+stack->size*(stack->count-1), stack->size);
        return 0;
    }else{
        bzero(data, stack->size);
        return -1;
    }
}
/**
 * to judge the array stack if empty
 */
int is_empty_array_stack(array_stack* stack){
    return stack->count <= 0 ? 1 : 0;
}
/**
 * to judge the array stack if full
 */
int is_full_array_stack(array_stack* stack){
    return stack->count > stack->max_size_stack ? 1 : 0;
}
/**
 * free the array stack
 */
void free_array_stack(array_stack* stack){
    free(stack->datap);
    stack->datap = NULL;
    stack->size = 0;
    stack->max_size_stack = 0;
    stack->count = 0;
    free(stack);
}
/**
 * empty the array stack
 */
void empty_array_stack(array_stack* stack){
    free(stack->datap);
    stack->datap = NULL;
    stack->count = 0;
    stack->datap = malloc(stack->size*stack->count);
}
