#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000
#define PI 3.14159265358979323846

int main()
{

    float *sin_values = (float *)calloc(N, sizeof(float));
    clock_t calc_init_start = clock();
    float summ = 0.0f;
    for (int i = 0; i < N; i++)
    {
        sin_values[i] = sinf(2 * PI * i / N);
    }
    for (int i = 0; i < N; i++)
    {
        summ += sin_values[i];
    }
    clock_t calc_init_end = clock();
    printf("Sum + initialization (CPU): %lf; time: %lf\n", summ, (double)(calc_init_end - calc_init_start) / CLOCKS_PER_SEC);

    free(sin_values);

    return 0;
}
