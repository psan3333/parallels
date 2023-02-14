#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000
#define PI 3.14159265358979323846
#define angle (2 * PI / N);
#define PGI_ACC_TIME 1

int main() {

    //инициализация и подсчёт суммы элементов массива на CPU
    double* sin_values = (double*)calloc(N, sizeof(double));
    clock_t calc_init_start = clock();
    double summ = 0.0f, calc_sin_angle = 0.0f;
    for (int i = 0; i < N; i++) {
        sin_values[i] = sin(calc_sin_angle);
        calc_sin_angle += angle;
        summ += sin_values[i];
    }
    clock_t calc_init_end = clock();
    printf("Sum + initialization (CPU): %lf; time: %lf\n", summ, (double)(calc_init_end - calc_init_start) / CLOCKS_PER_SEC);

    free(sin_values);

    return 0;
}
