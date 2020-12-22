#include <stdio.h>

int main () {
   FILE *fp;

   //menulis string dengan fput
   fp = fopen("file.txt", "w+"); 
   fputs("Halo-halo bandung", fp);
   fputs("Pada hari minggu kuturut ayah ke kota \n", fp);
   fputs("Test di baris baru\n\n", fp);
  
   // menulis perkarakter dengan fputc
   char str[4] = {'s', 'a', 't', 'u'};
   for (int i ; i<=4; i++) {
      fputc(str[i],fp);
   }   
   fclose(fp);
   return(0);
}
