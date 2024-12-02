#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern void imgCvtGrayIntToDouble(int width, int height, int* src, float* dst);
double measure_execution(int width, int height) {
    int* src = (int*)malloc(width * height * sizeof(int));
    float* dst = (float*)malloc(width * height * sizeof(float));
    for (int i = 0; i < width * height; i++) {
        src[i] = rand() % 256;
    }
    clock_t start = clock();
    imgCvtGrayIntToDouble(width, height, src, dst);
    clock_t end = clock();

    double time_ms = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

    free(src);
    free(dst);

    return time_ms;
}

int main() {
    srand(time(NULL));
    const int ITERATIONS = 30;
    FILE* results = fopen("performance_results.csv", "w");
    fprintf(results, "Width,Height,Average_Time_ms\n");

    for (int size = 0; size <= 1000; size += 10) {
        double total_time = 0.0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            total_time += measure_execution(size, size);
        }

        double avg_time = total_time / ITERATIONS;
        fprintf(results, "%d,%d,%.3f\n", size, size, avg_time);

        printf("Completed size %dx%d: Average time = %.3f ms\n", size, size, avg_time);
    }

    fclose(results);
    return 0;
}