#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern void imgCvtGrayIntToDouble(int width, int height, int* src, float* dst);

void imgCvtGrayIntToDouble_C(int width, int height, int* src, float* dst) {
    for (int i = 0; i < width * height; i++) {
        dst[i] = (float)src[i] / 255.0f;
    }
}

double measure_execution(int width, int height, int use_assembly) {
    int* src = (int*)malloc(width * height * sizeof(int));
    float* dst = (float*)malloc(width * height * sizeof(float));

    for (int i = 0; i < width * height; i++) {
        src[i] = rand() % 256;
    }

    clock_t start = clock();
    if (use_assembly) {
        imgCvtGrayIntToDouble(width, height, src, dst);
    }
    else {
        imgCvtGrayIntToDouble_C(width, height, src, dst);
    }
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
    fprintf(results, "Width,Height,Assembly_Time_ms,C_Time_ms,Speedup_Factor\n");

    for (int size = 0; size <= 1000; size += 10) {
        double total_time_asm = 0.0;
        double total_time_c = 0.0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            total_time_asm += measure_execution(size, size, 1);
            total_time_c += measure_execution(size, size, 0);
        }

        double avg_time_asm = total_time_asm / ITERATIONS;
        double avg_time_c = total_time_c / ITERATIONS;
        double speedup = avg_time_c / avg_time_asm;

        fprintf(results, "%d,%d,%.3f,%.3f,%.3f\n",
            size, size, avg_time_asm, avg_time_c, speedup);

        printf("Size %dx%d: ASM=%.3f ms, C=%.3f ms, Speedup=%.2fx\n",
            size, size, avg_time_asm, avg_time_c, speedup);
    }

    fclose(results);
    return 0;
}