#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asmhello();

// Pure C implementation nung kailangang gawin
// function below uses row-major order to represent the pixels
// Example:
/*
2, 3
1, 2, 3
4, 5, 6

array would be represented internally in memory as: 1,2,3,4,5,6

*/
void imgCvtGrayIntToDouble(int width, int height, int* pixels, float* converted) {
    for (int i = 0; i < width * height; i++) {
        converted[i] = pixels[i] / 255.0f;
    }
}

int main(int argc, char* argv[]) {
    asmhello();

    int w = 4;
    int h = 3;
    int pixels[12] = { 64, 89, 114, 84, 140, 166, 191, 84, 216, 242, 38, 84 }; // malloc this bih
    float res[12]; 

    imgCvtGrayIntToDouble(w, h, pixels, res);

    //output res
    for (int i = 0; i < w * h; i++) {
        printf("%.2f ", res[i]);
        if ((i + 1) % w == 0) {
            printf("\n");
        }
    }
    return 0;
}
