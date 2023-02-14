#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000
#define PI 3.14159265358979323846
#define angle (2 * PI / N);
#define PGI_ACC_TIME 1

void initialize_arr_gpu(double* sin_values) {
    double angle_for_sin_calc = 0;
    #pragma acc parallel loop gang worker num_workers(4) vector_length(32)
    for (int i = 0; i < N; i++){
        sin_values[i] = sin(angle_for_sin_calc);
        angle_for_sin_calc += angle;
    }
}

double summ_vals_gpu(double* sin_values){
    double summ = 0.0f;
    #pragma acc parallel loop reduction(+:summ)
    for (int i = 0; i < N; i++) {
        summ += sin_values[i];
    }
    return summ;
}

int main() {

    double* sin_values = (double*)calloc(N, sizeof(double));
    
    //подсчёт времени копирования данных с CPU на GPU
    clock_t start_copy = clock();
    #pragma acc data copy(sin_values[0:N])
    clock_t end_copy = clock();
    double copy_time = (double)(end_copy - start_copy) / CLOCKS_PER_SEC;
    printf("delta time 'pragma acc data copy(new_sin[0:N])': %lf\n", copy_time);
    
    //подсчёт времени инициализации и подсчёта суммы элементов массива на GPU
    clock_t calc_init_start = clock();
    initialize_arr_gpu(sin_values);
    double summ = summ_vals_gpu(sin_values);
    clock_t calc_init_end = clock();
    double calc_init_time = (double)(calc_init_end - calc_init_start) / CLOCKS_PER_SEC;
    printf("Sum + initialization (GPU): %lf; time: %lf\n", summ, calc_init_time);

    free(sin_values);

    return 0;
}
