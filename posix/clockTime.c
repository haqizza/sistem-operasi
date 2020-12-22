#include <time.h>
#include <stdio.h>
clock_t mulai, selesai;
double elapsed;

int main() {
    mulai = clock();
    for (int i = 1; i < 100000; i++)
    {
        for (int j = 1; j < 1000; j++) {
            for (int j = 1; j < 10; j++) {
            
            }
        }
    }
    selesai = clock();
    elapsed = ((double) (selesai - mulai)) / CLOCKS_PER_SEC;
    printf("Elapsed: %10.10f\n", elapsed);
}
