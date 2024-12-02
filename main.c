#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define BUFFER_SIZE 256

extern void imgCvtGrayIntToDouble();

// Pure C implementation nung kailangang gawin
// function below uses row-major order to represent the pixels
// Example:
/*
2, 3
1, 2, 3
4, 5, 6
array would be represented internally in memory as: 1,2,3,4,5,6
*/

int main(int argc, char* argv[]) {
    int width, height;

    // Get input - now reading height first, then width
    if (scanf_s("%d, %d", &height, &width) != 2) {
        fprintf(stderr, "Invalid input. Please provide dimensions in the format 'height, width'.\n");
        return 1;
    }

    // Allocate memory for data and res
    int* pixelArray = (int*)calloc(width * height, sizeof(int));
    float* convertedArray = (float*)calloc(width * height, sizeof(float));
    if (!pixelArray || !convertedArray) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read pixels as rows
    for (int i = 0; i < width * height; i++) {
        char inputRow[BUFFER_SIZE];
        char* token = NULL;
        char* context = NULL;

        if (scanf_s("%255s", inputRow, (unsigned)_countof(inputRow)) != 1) {
            fprintf(stderr, "Error reading input.\n");
            free(pixelArray);
            free(convertedArray);
            return 1;
        }

        token = strtok_s(inputRow, ", ", &context);
        while (token != NULL) {
            pixelArray[i] = atoi(token);
            token = strtok_s(NULL, ", ", &context);
        }
    }

    imgCvtGrayIntToDouble(height, width, pixelArray, convertedArray);

    for (int i = 0; i < width * height; i++) {
        printf("%.2f ", convertedArray[i]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    free(pixelArray);
    free(convertedArray);
    return 0;
}