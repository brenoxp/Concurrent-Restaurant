#include "student.h"
#include <stdio.h>

student_t* createStudent() {
    static int id;
    student_t *student = (student_t*) malloc(sizeof(student_t));
    student->id = id;
    student->ticket = 0;
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