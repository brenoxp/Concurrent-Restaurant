#include "student.h"
#include <math.h>

int main(int argc, char *argv[]) {
    
    student_t *student = createStudent();
    printStudent(student);
    deleteStudent(student);

    return 0;
}