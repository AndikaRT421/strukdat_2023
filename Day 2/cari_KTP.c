#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct_Func_Header.h"

void cari_KTP()
{
    system("clear");
    KTP isi_data;
    FILE *F_cuy = fopen("Data_KTP.bin", "rb+");

    if (F_cuy == NULL)
    {
        printf("File tidak bisa dibuka\n");
    }
    else
    {
        char nama_orang[100];
        printf("Silakan masukkan nama orang yang akan dicari:\n=>\t");
        scanf("\n%[^\n]%*c", nama_orang);

        int flag = 0;
        while (fread(&isi_data, sizeof(KTP), 1, F_cuy) > 0)
        {
            if (!strcmp(nama_orang, isi_data.nama))
            {
                if (flag == 1)
                {
                    printf("Terdapat duplikasi data!\n\n");
                }
                else
                {
                    flag = 1;
                    printf("\n\n");
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
                }
            }
        }
        if (flag == 0)
            printf("Data tidak ditemukan!\n\n");
    }

    fclose(F_cuy);
    printf ("\n\n");
}