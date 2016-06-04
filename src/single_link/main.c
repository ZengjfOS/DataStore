#include "single_linked.h"

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
int delete(void* data, void* linked_data);

int main(int argc, char** argv){
    /**
     * demo data
     */
    student students[4] = {
        {1,1},
        {2,2},
        {2,2},
        {3,3},
    };

    single_linked* header = create_single_linked(NULL, 0);

    int i = 0;
    printf("--------------source------------------>\n");
    for(i = 0; i < NR(students); i++){
        printf("student: id = %d, score = %d \n", students[i].id, students[i].score);
    }

    printf("--------------tail add---------------->\n");
    for(i = 0; i < NR(students); i++){
        //top_add_single_linked(&students[i], sizeof(student), header);
        tail_add_single_linked(&students[i], sizeof(student), header);
    }
    print_single_linked(header, print);

    empty_single_linked(header);

    printf("--------------top add---------------->\n");
    for(i = 0; i < NR(students); i++){
        //top_add_single_linked(&students[i], sizeof(student), header);
        top_add_single_linked(&students[i], sizeof(student), header);
    }
    print_single_linked(header, print);

    printf("--------------delete---------------->\n");
    student stu = {2,2};
    delete_single_linked(&stu, header, delete);
    print_single_linked(header, print);

    printf("---------------free----------------->\n");
    free_single_linked(header);
}

void print(void* data){
    student* stu = (((single_linked*)data)->datap);
    printf("student: id = %d, score = %d \n", stu->id, stu->score);
}
int delete(void* data, void* linked_data){
    return (((student*)data)->id == ((student*)linked_data)->id) && (((student*)data)->score == ((student*)linked_data)->score); 
}
