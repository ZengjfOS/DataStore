#include "double_linked.h"

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
void print(double_linked* node);
int delete(void* data, double_linked* node);

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
    double_linked* header = create_double_linked(NULL, 0);

    printf("--------------source--------------->\n");
    int i = 0;
    for(i = 0; i < NR(students); i++){
        printf("student: id = %d, score = %d\n", students[i].id, students[i].score);
    }

    printf("------------top add--------------->\n");
    for(i = 0; i < NR(students); i++){
        top_add_double_linked(&students[i],sizeof(student), header);
    }
    print_double_linked(header, print);

    empty_double_linked(header);

    printf("-----------tail add-------------->\n");
    for(i = 0; i < NR(students); i++){
        tail_add_double_linked(&students[i],sizeof(student), header);
    }
    print_double_linked(header, print);

    printf("-----------delete-------------->\n");
    student stu = {2,2};
    delete_double_linked(&stu, header, delete);
    print_double_linked(header, print);

    printf("-------------free-------------->\n");
    free_double_linked(header);
}
/**
 * impelement of the client print
 */
void print(double_linked* node){
    student* stu = (student*)(node->datap);
    printf("student: id = %d, score = %d\n", stu->id, stu->score);
}
/**
 * impelement of the client delete
 */
int delete(void* data, double_linked* node){
    student* stu = (student*)(node->datap);
    return (((student*)data)->id == stu->id) && (((student*)data)->score == stu->score);
}
