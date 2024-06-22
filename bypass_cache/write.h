#include <stdio.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <time.h>

double sequential_normal_write(unsigned int size);
double sequential_non_temporal_write(unsigned int size);
double random_normal_write(unsigned int size);
double random_non_temporal_write(unsigned int size);