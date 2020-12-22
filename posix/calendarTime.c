#include <time.h>
#include <stdio.h>

time_t  mulai, selesai;
double elapsed;

int main() {
    time(&mulai);
    for (int i = 1; i < 100000; i++)
    {
        for (int j = 1; j < 10000; j++) {}
    }
    time(&selesai);
    elapsed = difftime(selesai,mulai);
    printf("Elapsed: %10.10f\n", elapsed);
}
