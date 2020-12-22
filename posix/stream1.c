#include <stdio.h>

int main () {
   FILE * fp;
   fp = fopen ("file.txt", "w+");
   fprintf(fp, "%s %d %f %s", "Satu", 1, 0.5, "hello");  
   fclose(fp);

   //baca file
   char str1[10],str2[10];
   int int1;
   double float1;
   fp = fopen("file.txt","r");
   fscanf(fp,"%s %d %lf %s", str1, &int1, &float1, str2);
   printf(" isi file: %s ; %d ; %f ; %s \n",str1,int1,float1,str2);
   fclose(fp); 
   return(0);
}
