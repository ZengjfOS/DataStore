#include "array_stack.h"

#define NR(x) ((sizeof(x))/sizeof(x[0]))

/**
 * test struct
 */
typedef struct STUDENT{
	int id;
	int score;
}student;

void print(void* data);

int main(int argc, char** argv){
    array_stack* stack = create_array_stack(sizeof(student), 1024);

    printf("-----------push data--------->\n");
    student stu = {1,1};
    push_array_stack(&stu, stack);
    stu.id = 2;
    stu.id = 2;
    push_array_stack(&stu, stack);

    printf("----------print data--------->\n");
    print_array_stack(stack, print);

    printf("----------top data--------->\n");
    top_array_stack(&stu, stack);
    printf("stack data: id = %d, score = %d\n", stu.id, stu.score);

    printf("-----------pop data--------->\n");
    pop_array_stack(&stu, stack);
    printf("stack data: id = %d, score = %d\n", stu.id, stu.score);
    pop_array_stack(&stu, stack);
    printf("stack data: id = %d, score = %d\n", stu.id, stu.score);
    pop_array_stack(&stu, stack);
    printf("stack data: id = %d, score = %d\n", stu.id, stu.score);

    printf("----------top data--------->\n");
    top_array_stack(&stu, stack);
    printf("stack data: id = %d, score = %d\n", stu.id, stu.score);

    printf("-----------free data--------->\n");
    free_array_stack(stack);
}
void print(void* data){
    printf("stack data: id = %d, score = %d\n", ((student*)data)->id, ((student*)data)->score);
}
