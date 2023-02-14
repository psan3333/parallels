#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000
#define PI 3.14159265358979323846
#define angle (2 * PI / N);
#define PGI_ACC_TIME 1

int main() {

    double* new_sin = (double*)calloc(N, sizeof(double));
    clock_t start = clock();
    double summ = 0.0f, inc = 0.0f;
    for (int i = 0; i < N; i++) {
        new_sin[i] = sin(inc);
        inc += angle;
        summ += new_sin[i];
    }
    clock_t end = clock();
    printf("Sum 2: %lf; time: %lf\n", summ, (double)(end - start) / CLOCKS_PER_SEC);

    free(new_sin);

    return 0;
}
