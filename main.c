#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asmhello(); // This declares the assembly function we'll create

int main(int argc, char* argv[]) {
    asmhello();
    return 0;
}