#ifndef __STACK_H__
    #define __STACK_H__
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "myerror.h"

    typedef struct ARRAY_STACK{
        void* datap;
        int size;
        int count;
        int max_size_stack;
    }array_stack;

    typedef void (*array_stack_print)(void* data);

    /**
     * this work just for create a array stack
     */
    array_stack* create_array_stack(int data_size, int stack_size);
    /**
     * push the data to the array stack
     */
    int push_array_stack(void* data, array_stack* stack);
    /**
     * pop the data out of the array stack
     */
    int pop_array_stack(void* data, array_stack* stack);
    /**
     * this just use for print out of the array stack data
     * of couse, you can make it to file .
     */
    void print_array_stack(array_stack* stack, array_stack_print func);
    /**
     * get the data at the top of array stack
     */
    int top_array_stack(void* data, array_stack* stack);
    /**
     * to judge the array stack if empty
     */
    int is_empty_array_stack(array_stack* stack);
    /**
     * to judge the array stack if full
     */
    int is_full_array_stack(array_stack* stack);
    /**
     * free the array stack
     */
    void free_array_stack(array_stack* stack);
    /**
     * empty the array stack
     */
    void empty_array_stack(array_stack* stack);
#endif //__STACK_H__
