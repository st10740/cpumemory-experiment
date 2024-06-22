#include <stdio.h>
#include <stdlib.h>
#include "write.h"

#define arr_size 3000

int compare(const void *a, const void *b)
{
    if (*(double *) a > *(double *) b)
        return 1;
    else if (*(double *) a < *(double *) b)
        return -1;
    else
        return 0;
}

double avg_result(double (*func) (unsigned int), unsigned int size) {
    double result[20], avg = 0;
    int i;
    for (i = 0; i< 20; i++) {
        result[i] = func(size);
    }
    qsort(result, 20, sizeof(double), compare);
    for (i = 5; i<15; i++) {
        avg += result[i];
    }
    return avg / 10;
}

int main() {
    printf("normal write (sequential): %f\n", avg_result(sequential_normal_write, arr_size));
    printf("non-temporal write (sequential): %f\n", avg_result(sequential_non_temporal_write, arr_size));
    printf("normal write (random): %f\n", avg_result(random_normal_write, arr_size));
    printf("non-temporal write (random): %f\n", avg_result(random_non_temporal_write, arr_size));
    return 0;
}