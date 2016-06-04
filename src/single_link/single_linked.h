#ifndef __SINGLE_LINKED_H__
    #define __SINGLE_LINKED_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "myerror.h"
    
    typedef struct SINGLE_LINKED{
        void* datap;
        int size;
        struct SINGLE_LINKED* next;
    } single_linked;

    typedef void (*single_linked_print)(void* data);
    typedef int (*single_linked_delete)(void* data, void* linked_delete);
    /**
     * you should giving a vilid data dan size for save
     */
    int check_data_size(void *data, int size);
    /**
     * create a single linked header
     */
    single_linked* create_single_linked(void* data, int size);
    /**
     * add data to single linked at top
     */
    int top_add_single_linked(void* data, int size, single_linked* header);
    /**
     * add data to single linked at tail
     */
    int tail_add_single_linked(void* data, int size, single_linked* header);
    /**
     * delete data in single linked 
     */
    int delete_single_linked(void* data, single_linked* header, single_linked_delete func);
    /**
     * print all data in single linked
     */
    void print_single_linked(single_linked* header, single_linked_print func);
    /**
     * empty the single linked
     */
    void empty_single_linked(single_linked* header);
    /**
     * free all data in single linked
     */
    void free_single_linked(single_linked* header);
#endif  //__SINGLE_LINKED_H__
