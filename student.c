#include "student.h"
#include <stdio.h>

student_t* createStudent() {
    static int id;
    student_t *student = (student_t*) malloc(sizeof(student_t));
    student->id = id;
    student->ticket = getRandomInRange(0, 1);
    pthread_mutex_init(&student->lock, NULL);
    id++;
    return student;
}

void deleteStudent(student_t *student) {
    pthread_mutex_unlock(&student->lock);
    pthread_mutex_destroy(&student->lock);
    free(student);
}

void printStudent(student_t *student) {
    printf("Student %d have %d tickets\n", student->id, student->ticket);
}


// Execution of student
void *runStudent(void *student) {
    student_t *studentA = (student_t *) student;

    printStudent(studentA);
    deleteStudent(student);

    extern pthread_t *students;
    pthread_exit(students[studentA->id]);
}