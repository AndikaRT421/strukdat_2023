#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct_Func_Header.h"

void cari_KTP()
{
    system ("clear");
    KTP file_data;
    long long dicari;
    printf("\nMasukkan NIK yang dicari\n=>\t");
    scanf("%llu", &dicari);

    // test 1 : fseek seek_end -> fseek seek_set
    FILE *F_cuy = fopen("Data_KTP.bin", "rb+");
    if (F_cuy == NULL)
    {
        printf("Terjadi kesalahan. Tidak bisa cari KTP!");
    }
    else
    {
        fseek(F_cuy, 0, SEEK_END);
        KTP *isi_data;
        int x = ftell(F_cuy) / sizeof(KTP);
        isi_data = (KTP *)malloc(sizeof(KTP) * x);
        fseek(F_cuy, 0, SEEK_SET);
        if (isi_data == NULL)
        {
            printf("Gagal mengalokasi memori ke variabel struct !!!\n");
        }
        // Test 1 : fread dengan while + bikin 2 variable struct
        int indeks = 0;
        while (fread(&file_data, sizeof(KTP), 1, F_cuy) > 0)
        {
            isi_data[indeks].NIK = file_data.NIK;
            strcpy(isi_data[indeks].nama, file_data.nama);
            strcpy(isi_data[indeks].tempat_lahir, file_data.tempat_lahir);
            isi_data[indeks].tanggal = file_data.tanggal;
            isi_data[indeks].bulan = file_data.bulan;
            isi_data[indeks].tahun = file_data.tahun;
            isi_data[indeks].kelamin = file_data.kelamin;
            strcpy(isi_data[indeks].alamat, file_data.alamat);
            isi_data[indeks].agama = file_data.agama;
            strcpy(isi_data[indeks].pekerjaan, file_data.pekerjaan);

            indeks++;
        }
        qsort(isi_data, x, sizeof(KTP), banding);
        int index_dicari = Inter_Search(isi_data, 0, x - 1, dicari);
        // printf("INDEX : %d\n", index_dicari);

        if (index_dicari == -1)
        {
            printf("Data tidak ditemukan!!!\n");
        }
        else
        {
            printf("DATA YANG DICARI\n");
            printf("<=> NIK :\t\t %llu\n", isi_data[index_dicari].NIK);
            printf("<=> Nama:\t\t %s\n", isi_data[index_dicari].nama);
            printf("<=> Tempat Lahir:\t %s\n", isi_data[index_dicari].tempat_lahir);
            printf("<=> Tanggal Lahir:\t %d-%d-%d\n", isi_data[index_dicari].tanggal, isi_data[index_dicari].bulan, isi_data[index_dicari].tahun);
            switch (isi_data[index_dicari].kelamin)
            {
            case 1:
                printf("<=> Jenis Kelamin:\t Pria\n");
                break;
            case 2:
                printf("<=> Jenis Kelamin:\t Wanita\n");
                break;
            }
            printf("<=> Alamat Domisili:\t %s\n", isi_data[index_dicari].alamat);
            switch (isi_data[index_dicari].agama)
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
            printf("<=> Pekerjaan:\t\t %s\n", isi_data[index_dicari].pekerjaan);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        }
        free(isi_data);
    }
    fclose(F_cuy);
}