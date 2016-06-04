#include "double_linked.h"
void init_double_linked_node(double_linked* node){
    node->next = node;
    node->pre = node;
    node->datap = NULL;
    node->size = 0;
}

int check_data_size(void* data, int size){
    return ((data != NULL) && (size > 0));
}
/**
 * create a double linked for user
 */
double_linked* create_double_linked(void* data, int size){
    double_linked* header = malloc(sizeof(double_linked));
    ERR(1, NULL == header, goto err, "create double linked fail\n");
    
    init_double_linked_node(header);

    if(check_data_size(data, size)){
        void* new_data = malloc(size);
        ERR(1, NULL == new_data, goto err, "create double linked data fail\n");
        memcpy(new_data, data, size);
        header->size = size;
        header->datap = new_data;
    }

    return header;
err:
    return NULL;
}
void _add_double_linked(double_linked* current, double_linked* pre, double_linked* next){
    pre->next = current;
    current->next = next;
    next->pre = current;
    current->pre = pre;
}
/**
 * top add doulbe linked
 */
int top_add_double_linked(void* data, int size, double_linked* header){
    if(check_data_size(data, size)){
        double_linked* node = malloc(sizeof(double_linked));
        ERR(1, NULL == header, goto err, "create note fail.\n");

        init_double_linked_node(node);

        void* new_data = malloc(size);
        ERR(1, NULL == new_data, goto err, "create note data fail.\n");
        memcpy(new_data, data, size);
        node->size = size;
        node->datap = new_data;
        _add_double_linked(node, header, header->next);
        return 0;
    }
err:
    return -1;
}
/**
 * tail add double linked
 */
int tail_add_double_linked(void* data, int size, double_linked* header){
    if(check_data_size(data, size)){
        double_linked* node = malloc(sizeof(double_linked));
        ERR(1, NULL == header, goto err, "create note fail.\n");

        init_double_linked_node(node);

        void* new_data = malloc(size);
        ERR(1, NULL == new_data, goto err, "create note data fail.\n");
        memcpy(new_data, data, size);
        node->size = size;
        node->datap = new_data;
        _add_double_linked(node, header->pre, header);
        return 0;
    }
err:
    return -1;
    
}
/**
 * print all data in double linked
 */
void print_double_linked(double_linked* header, double_linked_print func){
    double_linked* tmp = header->next;
    while(tmp != header){
        func(tmp);
        tmp = tmp->next;
    }
}
void _delete_double_linked_node(double_linked* pre, double_linked* next){
    pre->next = next;
    next->pre = pre;
}
void delete_double_linked_node(double_linked* node){
    _delete_double_linked_node(node->pre, node->next);
    if(node->datap){
        free(node->datap);
    }
    init_double_linked_node(node);
    free(node);
}
/**
 * empty all data in double linked
 */
void empty_double_linked(double_linked* header){
    double_linked* tmp = header->next;
    double_linked* pre = header;
    while(tmp != header){
        pre = tmp;
        tmp = tmp->next;
        delete_double_linked_node(pre);
    }
    init_double_linked_node(header);
    if(header->datap)
        free(header->datap);
    header->datap = NULL;
    header->size = 0;
}
/**
 * delete a element in the double linked
 */
void delete_double_linked(void* data, double_linked* header, double_linked_delete func){
    double_linked* tmp = header->next;
    double_linked* pre = header;
    while(tmp != header){
        pre = tmp;
        tmp = tmp->next;
        if(func(data, pre)){
            delete_double_linked_node(pre);
        }
    }
}
void free_double_linked(double_linked* header){
    double_linked* tmp = header->next;
    double_linked* pre = header;
    while(tmp != header){
        pre = tmp;
        tmp = tmp->next;
        delete_double_linked_node(pre);
    }

    init_double_linked_node(header);
    if(header->datap)
        free(header->datap);
    header->datap = NULL;
    header->size = 0;
    free(header);
}
