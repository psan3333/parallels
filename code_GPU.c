#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000
#define PI 3.14159265358979323846
#define angle (2 * PI / N);

void initialize_arr_gpu(double *sin_values)
{
    double angle_for_sin_calc = 0;
    #pragma acc parallel loop gang worker num_workers(4) vector_length(32)
    for (int i = 0; i < N; i++)
    {
        sin_values[i] = sin(angle_for_sin_calc);
        angle_for_sin_calc += angle;
    }
}

double summ_vals_gpu(double *sin_values)
{
    double summ = 0.0f;
    #pragma acc parallel loop reduction(+:summ)
    for (int i = 0; i < N; i++)
    {
        summ += sin_values[i];
    }
    return summ;
}

int main()
{

    double *sin_values = (double *)calloc(N, sizeof(double));
    clock_t start = clock();
    initialize_arr_gpu(sin_values);
    double summ = summ_vals_gpu(sin_values);

    clock_t end = clock();
    printf("Sum: %lf; time: %lf\n", summ, (double)(end - start) / CLOCKS_PER_SEC);

    free(sin_values);

    return 0;
}
