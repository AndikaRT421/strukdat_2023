#include <stdio.h>
#include <stdlib.h>
#include "Struct_Func_Header.h"

void load_KTP(int jumlah_data)
{
    // Your code goes here
    system("clear");
    FILE *F_cuy = fopen("Data_KTP.bin", "rb+");
    KTP isi_data;
    if (F_cuy == NULL)
        printf("Terjadi kesalahan. Tidak bisa load data KTP!\n");
    else
    {
        int x = 1;
        while (fread(&isi_data, sizeof(KTP), 1, F_cuy) > 0)
        {
            printf("\t[Data %d]\n", x);
            printf("<=> NIK:\t\t %s\n", isi_data.NIK);
            printf("<=> Nama:\t\t %s\n", isi_data.nama);
            printf("<=> Tempat Lahir:\t %s\n", isi_data.tempat_lahir);
            printf("<=> Tanggal Lahir:\t %d-%d-%d\n", isi_data.tanggal, isi_data.bulan, isi_data.tahun);
            switch (isi_data.kelamin)
            {
            case 1:
                printf("<=> Jenis Kelamin:\t Pria\n");
                break;
            case 2:
                printf("<=> Jenis Kelamin:\t Wanita\n");
                break;
            }
            printf("<=> Alamat Domisili:\t %s\n", isi_data.alamat);
            switch (isi_data.agama)
            {
            case 1:
                printf("<=> Agama:\t\t Islam\n");
                break;
            case 2:
                printf("<=> Agama:\t\t Kristen\n");
                break;
            case 3:
                printf("<=> Agama:\t\t Katolik\n");
                break;
            case 4:
                printf("<=> Agama:\t\t Hindu\n");
                break;
            case 5:
                printf("<=> Agama:\t\t Buddha\n");
                break;
            case 6:
                printf("<=> Agama:\t\t Konghuchu\n");
                break;
            }
            printf("<=> Pekerjaan:\t\t %s\n", isi_data.pekerjaan);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            x++;
        }
        printf("TOTAL DATA: %d", x - 1);
        if (x-1 == jumlah_data)
            printf(" & data sama dengan jumlah input\n");
        else
        {
            printf(" & data TIDAK SAMA dengan jumlah input\n");
            printf("Jumlah input = %d\n", jumlah_data);
        }
    }
    fclose(F_cuy);
    printf("\n\n");
}