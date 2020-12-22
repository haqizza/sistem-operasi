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
   fclose(fp);
    fp = fopen("file1.txt", "w+"); 
   while ( fgets (str, 60, fp)!=NULL ) {
      /* tulis ke stdout */
      str[strcspn(str, "a")] = 'o'; //membuang ekstra /n
      fputs(str,fp);
   }
   //menulis string dengan fput
   
   
   
   // menulis perkarakter dengan fputc
//    char str[4] = {'s', 'a', 't', 'u'};
//    for (int i ; i<=4; i++) {
//       fputc(str[i],fp);
//    }   
   fclose(fp);
   return(0);
}
