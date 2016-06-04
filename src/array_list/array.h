#ifndef __ARRAY_H__
	#define __ARRAY_H__
	
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "myerror.h"
	
	#define ARRAY_NR(x) (sizeof(x)/sizeof(x[0]))
	
	typedef struct array_list{
		void*	datap;
		int		size;
		int		count;
	} ARRAY_LIST;

	typedef int (*array_list_delete)(void* data, void* iterate_date);
	typedef void (*array_list_print)(void* data);
	
	/**
	 * create the header of array_list
	 */
	ARRAY_LIST* create_array_list(int size);
	/**
	 * top add to the array list
	 */
	int top_add_array_list(void* data, ARRAY_LIST* header);
	/**
	 * tail add to the array list 
	 */
	int tail_add_array_list(void* data, ARRAY_LIST*	header);
	/**
	 * delete the giving data int he array list
	 */
	int delete_array_list(void *data, ARRAY_LIST* header, array_list_delete func);
	/**
	 * insert to array list with the index
	 */
	int insert_array_list(void* data, int index, ARRAY_LIST* header);
	/**
	 * delete all array list element
	 */
	int empty_array_list(ARRAY_LIST* header);
	/**
	 * print all element of the array list
	 */
	void print_array_list(ARRAY_LIST* header, array_list_print func);
	/**
	 * free all of data
	 */
	void free_array_list(ARRAY_LIST* header);
	
#endif
