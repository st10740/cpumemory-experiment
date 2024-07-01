double res[N][N] __attribute__ ((aligned (64)));
double mul1[N][N] __attribute__ ((aligned (64)));
double mul2[N][N] __attribute__ ((aligned (64)));

int main() {
    int i, j, k;
    
    // initialize mul1 and mul2
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            mul1[i][j] = i + j;
            mul2[i][j] = i + j;
        }
    }

    // matrix multiplication
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            for (k = 0; k < N; ++k)
                res[i][j] += mul1[i][k] * mul2[k][j];
    return 0;
}

