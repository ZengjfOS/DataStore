#include "array_queue.h"
/**
 * create a array queue for use
 */
array_queue* create_array_queue(int data_size, int queue_size){
    ERR(1, ((data_size <= 0) || (queue_size <= 0)), goto err, "create array queue argument was NULL");
    array_queue* queue = malloc(sizeof(array_queue));
    ERR(1, NULL == queue, goto err, "create array queue fail.\n");

    queue->size = data_size;
    queue->max_size_queue = queue_size;
    queue->datap = NULL;
    queue->head = 0;
    queue->tail = 0;

    queue->datap = malloc(queue->size*queue->max_size_queue);
    ERR(1, NULL == queue->datap, goto err1, "create array queue array fail.\n");

    return queue;
err1:
    free(queue);
err:
    return NULL;
}
/**
 * put the data to the array queue
 */
int enque_array_queue(void* data, array_queue* queue){
    ERR(1, ((NULL== queue) || (NULL == data)), return -1, "enque array queue argument was NULL");
    if(!is_full_array_queue(queue)){
        memcpy(queue->datap+(queue->head*queue->size), data, queue->size);
        queue->head = (queue->head+1)%queue->max_size_queue;
        return 0;
    }
    return -1;
}
/**
 * get out the data from the array queue
 */
int deque_array_queue(void* data, array_queue* queue){
    ERR(1, (NULL== queue) || (NULL == data), return, "deque array queue argument was NULL");
    if(!is_empty_array_queue(queue)){
        memcpy(data, queue->datap+(queue->tail*queue->size), queue->size);
        queue->tail = (queue->tail+1)%queue->max_size_queue;
        return 0;
    }else{
        bzero(data, queue->size);
        return -1;
    }
}
/**
 * print all data from the array queue
 */
void print_array_queue(array_queue* queue, array_queue_print func){
    ERR(1, (NULL== queue) || (NULL == func), return, "print array queue argument was NULL");
    int i = queue->tail;
    while((i%queue->max_size_queue) != queue->head){
        func(queue->datap+queue->size*i);
        i = (++i)%queue->max_size_queue;
    }
}
/**
 * judge the array queue is empty or not
 */
int is_empty_array_queue(array_queue* queue){
    ERR(1, NULL == queue, return, "judge if empty array  queue argument was NULL");
    return queue->tail == queue->head;
}
/**
 * judge the array queue is full or not
 */
int is_full_array_queue(array_queue* queue){
    ERR(1, NULL == queue, return, "judge if full array  queue argument was NULL");
    return ((queue->head+1)%queue->max_size_queue) == queue->tail;
}
/**
 * make the array queue to empty
 */
void empty_array_queue(array_queue* queue){
    ERR(1, NULL == queue, return, "empty queue was NULL");
    free(queue->datap);
    queue->datap = malloc(queue->size*queue->max_size_queue);
}
/**
 * free the array queue
 */
void free_array_queue(array_queue* queue){
    ERR(1, NULL == queue, return, "free queue was NULL");
    free(queue->datap);
    free(queue);
}
