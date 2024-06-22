# include "write.h"

double sequential_normal_write(unsigned int size) {
    int arr[size][size], i, j;
    clock_t start, end;
    double time;

    start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            arr[i][j] = i + j;
        }
    }
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

double sequential_non_temporal_write(unsigned int size) {
    int arr[size][size], i, j;
    clock_t start, end;
    double time;
    
    start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            _mm_stream_si32(&arr[i][j], i + j);
        }
    }
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

double random_normal_write(unsigned int size) {
    int arr[size][size], i, j;
    clock_t start, end;
    double time;

    start = clock();
    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i++) {
            arr[i][j] = i + j;
        }
    }
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

double random_non_temporal_write(unsigned int size) {
    int arr[size][size], i, j;
    clock_t start, end;
    double time;

    start = clock();
    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i++) {
            _mm_stream_si32(&arr[i][j], i + j);
        }
    }
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}