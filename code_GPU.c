#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000
#define PI 3.14159265358979323846
#define PGI_ACC_TIME 1

int main()
{
    double *sin_values = (double *)calloc(N, sizeof(double));
    #pragma acc data create(sin_values[:N])

    #pragma acc parallel loop
    for (int i = 0; i < N; i++)
    {
        sin_values[i] = sin(2 * PI / N * i);
    }
    
    double summ = 0.0f;
    #pragma acc parallel loop reduction(+:summ)
    for (int i = 0; i < N; i++)
    {
        summ += sin_values[i];
    }

    printf("Sum: %lf\n", summ);

    free(sin_values);

    return 0;
}
