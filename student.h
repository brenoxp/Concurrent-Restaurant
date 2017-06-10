#ifndef STUDENT_H_
#define STUDENT_H_

#include <pthread.h>
#include <stdlib.h>

typedef struct student {
    int id;
    char ticket;
    pthread_mutex_t lock;
} student_t;

student_t* createStudent();
void deleteStudent(student_t *student);
void printStudent(student_t *student);

#endif // STUDENT_H_