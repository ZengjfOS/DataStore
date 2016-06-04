#include "array_queue.h"

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
    array_queue* queue = create_array_queue(sizeof(student), 10);

    printf("------------------enque----------------->\n");
    student stu = {1, 1};
    enque_array_queue(&stu, queue);
    enque_array_queue(&stu, queue);
    enque_array_queue(&stu, queue);

    stu.id = 2;
    stu.id = 2;
    enque_array_queue(&stu, queue);
    print_array_queue(queue,print);

    printf("-----------------deque----------------->\n");
    deque_array_queue(&stu, queue);
    printf("student: id = %d, score = %d\n", stu.id, stu.score);
    deque_array_queue(&stu, queue);
    printf("student: id = %d, score = %d\n", stu.id, stu.score);

    printf("-----------------queue----------------->\n");
    print_array_queue(queue,print);

    printf("-----------------freed----------------->\n");
    free_array_queue(queue);
}
void print(void* data){
    student* stu = (student*)data;
    printf("queue student: id = %d, score = %d\n", stu->id, stu->score);
}
