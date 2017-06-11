#include "tools.h"

int getRandomInRange(int minimum_number, int max_number) {
    return rand() % (max_number + 1 - minimum_number) + minimum_number; 
}