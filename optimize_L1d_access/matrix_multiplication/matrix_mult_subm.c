#include <emmintrin.h>
double res[N][N] __attribute__ ((aligned (64)));
double mul1[N][N] __attribute__ ((aligned (64)));
double mul2[N][N] __attribute__ ((aligned (64)));
#define CLS 64
#define SM (CLS / sizeof (double))

int main (void)
{
    int i, i2, j, j2, k, k2;
    double *restrict rres;
    double *restrict rmul1;
    double *restrict rmul2;

    // initialize mul1 and mul2
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            mul1[i][j] = i + j;
            mul2[i][j] = i + j;
        }
    }

    // matrix mulplication
    for (i = 0; i < N; i += SM)
        for (j = 0; j < N; j += SM)
            for (k = 0; k < N; k += SM)
                for (i2 = 0, rres = &res[i][j],
                    rmul1 = &mul1[i][k]; i2 < SM;
                    ++i2, rres += N, rmul1 += N)
                    for (k2 = 0, rmul2 = &mul2[k][j];
                        k2 < SM; ++k2, rmul2 += N)
                        for (j2 = 0; j2 < SM; ++j2)
                            rres[j2] += rmul1[k2] * rmul2[j2];

    return 0;
}