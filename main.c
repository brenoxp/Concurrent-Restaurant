#include <stdio.h>
#include "student.h"
#include "tools.h"

pthread_t *students;

int main(int argc, char *argv[]) {
    
    // Create a random number of students 10 to 50
    srand(time(NULL));
    int numberOfStudents = getRandomInRange(10, 50);

    students = malloc(sizeof(pthread_t) * numberOfStudents);

    for (int i = 0; i < numberOfStudents; i++) {
        pthread_create(&students[i], NULL, runStudent, (void *) createStudent());
        pthread_join(students[i],NULL);
    }

    free(students);

    return 0;
}