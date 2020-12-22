#include <stdio.h>

typedef struct Mahasiswa
{
      char nim[10];
      char nama[25];
      float nilai;
} Mahasiswa;

int  main()
{
      FILE *fp;
      Mahasiswa mhs1, mhs2; //nantinya array

      fp = fopen("mhs.dat","w");

      if(fp == NULL) {
         perror("Gagal membuka file");
         return(-1);
      }

      mhs1 = (Mahasiswa) {.nim="13594022", .nama="Budi Martami", .nilai=70.85};
      fwrite(&mhs1,sizeof(mhs1),1,fp);
      mhs2 = (Mahasiswa) {.nim="13594036", .nama="Elfan Noviari", .nilai=80.05};
      fwrite(&mhs2,sizeof(mhs2),1,fp);
      fclose(fp);

      //baca file
      fp = fopen("mhs.dat","r");
      if(fp == NULL) {
         perror("Gagal membuka file");
         return(-1);
      }
      struct Mahasiswa mhsout;
      if(fp == NULL) {
         perror("Gagal membuka file");
         return(-1);
      }

      while(fread(&mhsout,sizeof(mhsout),1,fp)>0)
          printf("\n\t%s\t%s\t%f",mhsout.nim,mhsout.nama,mhsout.nilai);

      printf("\n\n");
      fclose(fp);

}
