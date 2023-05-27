#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct_Func_Header.h"

void hapus_KTP(int *jumlah_data)
{
    system ("clear");
    FILE *F_cuy;
    FILE *F_copas;
    int flag = 0;
    KTP isi_data;

    F_cuy = fopen("Data_KTP.bin", "rb+");
    if (F_cuy == NULL)
    {
        printf("Tidak dapat membuka file [Data_KTP.bin]\n");
    }
    F_copas = fopen("Copas_KTP.bin", "wb+");
    if (F_copas == NULL)
    {
        printf("Tidak dapat membuka file [Copas_KTP.bin]\n");
    }

    char nama_orang[100];
    printf("Silakan masukkan nama orang yang akan dihapus:\n=>\t");
    scanf("\n%[^\n]%*c", nama_orang);

    while (fread(&isi_data, sizeof(KTP), 1, F_cuy) > 0)
    {
        if (strcmp(nama_orang, isi_data.nama) == 0)
        {
            printf("Nama telah dihapus.\n\n");
            flag = 1;
            *jumlah_data--;
        }
        else
        {
            fwrite(&isi_data, sizeof(KTP), 1, F_copas);
        }
    }
    if (flag == 0)
    {
        printf("Nama tidak ditemukan\n\n");
    }

    fclose(F_cuy);
    fclose(F_copas);

    remove("Data_KTP.bin");
    rename("Copas_KTP.bin", "Data_KTP.bin");
    printf ("\n\n");
}