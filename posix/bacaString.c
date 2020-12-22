#include <stdio.h>
#include <string.h>

int main () {
   FILE *fp;
   char str[60];  //buffer

   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Gagal membuka file");
      return(-1);
   }
   while ( fgets (str, 60, fp)!=NULL ) {
      /* tulis ke stdout */
      str[strcspn(str, "\n")] = 0; //membuang ekstra /n
      puts(str);
   }
   fclose(fp);
   return(0);
}
