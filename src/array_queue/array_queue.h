#ifndef __ARRAY_QUEUE_H__
    #define __ARRAY_QUEUE_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "myerror.h"

    typedef struct ARRAY_DUEUE{
        int head;
        int tail;
        int size;
        int max_size_queue;
        void* datap;
    }array_queue;

    typedef void(*array_queue_print)(void* data);

    /**
     * create a array queue for use
     */
    array_queue* create_array_queue(int data_size, int queue_size);
    /**
     * put the data to the array queue
     */
    int enque_array_queue(void* data, array_queue* queue);
    /**
     * get out the data from the array queue
     */
    int deque_array_queue(void* data, array_queue* queue);
    /**
     * print all data from the array queue
     */
    void print_array_queue(array_queue* queue, array_queue_print func);
    /**
     * judge the array queue is empty or not
     */
    int is_empty_array_queue(array_queue* queue);
    /**
     * judge the array queue is full or not
     */
    int is_full_array_queue(array_queue* queue);
    /**
     * make the array queue to empty
     */
    void empty_array_queue(array_queue* queue);
    /**
     * free the array queue
     */
    void free_array_queue(array_queue* queue);

#endif
