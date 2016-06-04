#ifndef __DOUBLE_LINK_H__
    #define __DOUBLE_LINK_H__
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "myerror.h"
    #include <string.h>

    typedef struct DOUBLE_LINKED{
        void* datap;
        int size;
        struct DOUBLE_LINKED* pre;
        struct DOUBLE_LINKED* next;
    } double_linked;

    typedef void(*double_linked_print)(double_linked* data);
    typedef int(*double_linked_delete)(void* data, double_linked* linked_data);

    void init_double_linked_node(double_linked* node);
    int check_data_size(void* data, int size);
    void empty_double_linked(double_linked* header);
    void _delete_double_linked_node(double_linked* pre, double_linked* next);
    void delete_double_linked_node(double_linked* node);
    /**
     * create a double linked for user
     */
    double_linked* create_double_linked(void* data, int size);
    void _add_double_linked(double_linked* current, double_linked* pre, double_linked* next);
    /**
     * top add doulbe linked
     */
    int top_add_double_linked(void* data, int size, double_linked* header);
    /**
     * tail add double linked
     */
    int tail_add_double_linked(void* data, int size, double_linked* header);
    /**
     * print all data in double linked
     */
    void print_double_linked(double_linked* header, double_linked_print func);
    /**
     * empty all data in double linked
     */
    void empty_double_linked(double_linked* header);
    /**
     * delete a element in the double linked
     */
    void delete_double_linked(void* data, double_linked* header, double_linked_delete func);
    /**
     * free all data in the double linked
     */
    void free_double_linked(double_linked* header);
#endif
