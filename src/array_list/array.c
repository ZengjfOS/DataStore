#include "array.h"

/**
 * create the header of array_list
 */
ARRAY_LIST* create_array_list(int size){
	ERR(1, size <= 0, goto err, "create array list with size <= 0.\n");

	ARRAY_LIST* header = malloc(sizeof(ARRAY_LIST));
	ERR(1, NULL == header, goto err, "malloc array list failed.\n");

	header->size = size;
	header->count = 0;
	header->datap = malloc(header->size * header->count);
	return header;
err:
	return NULL;
}
/**
 * top add to the array list
 */
int top_add_array_list(void* data, ARRAY_LIST* header){
	ERR(1, NULL == header, goto err, "top add array list with the NULL value for func.\n");

	void* new_datap = malloc((header->size)*(header->count+1));
	ERR(1, NULL == new_datap, goto err, "top add array list element failed.\n");

	memcpy(new_datap, data, header->size);
	memcpy( new_datap+(header->size) , header->datap, (header->size)*(header->count));

	header->count++;
	free(header->datap);
	header->datap = new_datap;

	return 0;
err:
	return -1;
}
/**
 * tail add to the array list 
 */
int tail_add_array_list(void* data, ARRAY_LIST*	header){
	ERR(1, NULL == header, goto err, "tail add array list with the NULL value for func.\n");

	void* new_datap = malloc((header->size)*(header->count + 1));
	ERR(1, NULL == new_datap, goto err, "tail add array list element failed.\n");

	memcpy(new_datap, header->datap, (header->size)*(header->count));
	memcpy(new_datap+(header->size)*(header->count), data, header->size);
	header->count++;
	free(header->datap);
	header->datap = new_datap;

	return 0;
err:
	return -1;
}
/**
 * delete the giving data int he array list
 */
int delete_array_list(void* data, ARRAY_LIST* header, array_list_delete func){
	ERR(1, ((NULL == header) || (NULL == func)), goto err, "delete array list with the NULL value.\n");

	int i = 0;
	int count = header->count;
	for(; i < count; i++){
		if(func(data, header->datap+(header->size*i))){
			void* new_datap = calloc((header->count-1), header->size);
			ERR(1, NULL == new_datap, goto err, "delete array list element fail.\n");
			/**
			 * i had pazzled with the (header->size*i) --> (header->size*(i-1))
			 */
			memcpy(new_datap, header->datap, header->size*i);
			memcpy(new_datap+header->size*i, header->datap+header->size*(i+1), header->size*(header->count-i-1));
			header->count--;
			free(header->datap);
			header->datap = new_datap;
		}
	}
	return 0;
err:
	return -1;
}
/**
 * print all element of the array list
 */
void print_array_list(ARRAY_LIST* header, array_list_print func){
	ERR(1, ((NULL == header) || (NULL == func)), return, "print array list with the NULL value.\n");

	int i = 0;
	int count = header->count;
	for(; i < count; i++){
		func( (header->datap)+( i*(header->size) ) );
	}
}
void free_array_list(ARRAY_LIST* header){
	ERR(1, NULL == header, return, "free array list with the NULL value for header.\n");

	free(header->datap);
	free(header);
}
int empty_array_list(ARRAY_LIST* header){
	ERR(1, NULL == header, goto err, "empty array list with the NULL value for header.\n");

	free(header->datap);
	header->count = 0;
	/**
	 * just for next to add elemnt,the header_datap should not NULL
	 */
	header->datap = malloc(header->count * header->size);
	return 0;
err:
	return -1;
}

int insert_array_list(void* data, int index, ARRAY_LIST* header){
	ERR(1, NULL == header, goto err, "insert array list with the NULL value for header.\n");

	/**
	 * just to prevent out of the bound
	 */
	if(index < 1)
		index = 1;
	if(index > header->count)
		index = header->count+1;

	void* new_datap = calloc((header->count+1), header->size);
	ERR(1, NULL == new_datap, goto err, "delete array list element fail.\n");

	memcpy(new_datap, header->datap, header->size*(index-1));
	memcpy(new_datap+header->size*(index-1), data, header->size);
	memcpy(new_datap+header->size*index, header->datap+header->size*(index-1), header->size*(header->count-(index-1)));
	header->count++;
	free(header->datap);
	header->datap = new_datap;
	return 0;
err:
	return -1;
}
