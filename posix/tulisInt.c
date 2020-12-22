#include <stdio.h>
int main ()
{
   FILE *fp;
   int i=2, j=3, k=4;
   fp  = fopen ("fileint.bin","w");
   if(fp == NULL) {
      perror("Gagal membuka file");
      return(-1);
   }
   putw(i, fp);
   putw(j, fp);
   putw(k, fp);
   fclose(fp);

   //baca file 
   int n;
   fp  = fopen ("fileint.bin","r");
   if(fp == NULL) {
      perror("Gagal membuka file");
      return(-1);
   }
   while(1)
   {
      n = getw(fp);
      if (n == EOF) {break;}
      printf("Nilai: %d \n", n);
   }
   fclose(fp);
   return 0;
}
