#include <time.h>
#include <sys/time.h>
#include <stdio.h>

struct timeval waktu, mulai, selesai;
double elapsed;
int main() {
   gettimeofday(&waktu,NULL);
   printf("detik:%ld \nmicro detik:%ld\n", waktu.tv_sec,waktu.tv_usec);

   //formating
   time_t t;
   struct tm *info;
   char buffer[64];
   
   t = waktu.tv_sec;
   info = localtime(&t); //ambil infonya
   printf("format standard: %s", asctime (info));
   strftime (buffer, sizeof buffer, "Hari ini  %A, %B %d.\n", info);
   printf("%s",buffer);
   strftime (buffer, sizeof buffer, "Waktu:  %I:%M %p.\n", info);
   printf("%s",buffer);

// Latihan
//     gettimeofday(&mulai,NULL);
//     for (int i = 1; i < 100000; i++)
//     {
//         for (int j = 1; j < 100000; j++) {}
//     }
//     gettimeofday(&selesai,NULL);
//     elapsed = &selesai.tv_sec - &mulai.tv_sec;
//     printf("Elapsed: %10.10f\n", elapsed);
}