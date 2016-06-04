#include "array.h"

#define NR(x) ((sizeof(x))/sizeof(x[0]))

/**
 * test struct
 */
typedef struct STUDENT{
	int id;
	int score;
}student;

/**
 * callback function
 */
void print(void* data);
int delete(void* data, void* iterate_data);

int main(int argc, char** argv){
	/**
	 * demo data
	 */
	student students[4] = {
		{1, 40},
		{2, 50},
		{3, 60},
		{3, 60},
	};

	ARRAY_LIST* header = create_array_list(sizeof(student));
	ERR(1, NULL == header, goto err, "main create array list fail.\n");

	printf("\n---------------source------------------>\n");
	int i = 0;
	for(; i < NR(students); i++){
		printf("\033[32mstudent: id = %d, score = %d \033[0m\n", students[i].id, students[i].score);
	}

	printf("\n-------------tail add------------------>\n");
	for(i = 0; i < NR(students); i++){
		tail_add_array_list(&students[i], header);
	}
	print_array_list(header, print);
	empty_array_list(header);

	printf("\n--------------top add------------------>\n");
	for(i = 0; i < NR(students); i++){
		top_add_array_list(&students[i], header);
	}
	print_array_list(header, print);


	student del_stu = {1, 40};
	printf("\n------------delete array list------------>\n");
	delete_array_list(&del_stu, header, delete);
	print_array_list(header, print);

	printf("\n------------insert array list------------>\n");
	student insert_stu = {4, 40};
	insert_array_list(&insert_stu, 0, header);
	print_array_list(header, print);

	printf("\n----------had freed array list----------->\n");
	free_array_list(header);

	return 0;
err:
	return -1;
}

/**
 * implement of the output to stdout
 */
void print(void* data){
	printf("student: id = %d, score = %d\n", ((student*)data)->id, ((student*)data)->score);
}

/**
 * implement of the delete function
 */
int delete(void* data, void* iterate_data){
	return (((student*)data)->id == ((student*)iterate_data)->id) && (((student*)data)->score == ((student*)iterate_data)->score);
}

