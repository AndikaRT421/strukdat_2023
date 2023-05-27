#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct_Func_Header.h"

void input_KTP(int *jumlah_data)
{
    // Your code goes here
    system("clear");
    KTP isi_data;
    FILE *F_cuy = fopen("Data_KTP.bin", "ab+");

    if (F_cuy == NULL)
    {
        printf("Terjadi kesalahan. Tidak bisa input KTP!\n");
    }
    else
    {
        while (1)
        {
            printf("Silakan masukkan NIK Anda:");
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.NIK);

            printf("\nSilakan masukkan nama Anda:");
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.nama);

            printf("\nSilakan masukkan tempat kelahiran Anda:");
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.tempat_lahir);

            printf("\nSilakan masukkan tanggal, bulan, tahun kelahiram Anda:");
            printf("\n[Contoh: 1-12-2002]");
            printf("\n=>\t");
            scanf("%d-%d-%d", &isi_data.tanggal, &isi_data.bulan, &isi_data.tahun);

            printf("\nSilakan masukkan jenis kelamin Anda:\t{1. Pria}\t{2. Wanita}");
            printf("\n[Cukup masukkan kode angkanya saja]");
            printf("\n=>\t");
            scanf("%d", &isi_data.kelamin);

            printf("\nSilakan masukkan alamat domisili Anda:");
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.alamat);

            printf("\nSilakan masukkan agama Anda:");
            printf("\n\t\t {1. Islam}\t{2. Kristen}\t{3. Katolik}");
            printf("\n\t\t {4. Hindu}\t{5. Buddha}\t{6. Konghuchu}");
            printf("\n[Cukup masukkan kode angkanya saja]");
            printf("\n=>\t");
            scanf("%d", &isi_data.agama);

            printf("\nSilakan masukkan jenis pekerjaan Anda:");
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.pekerjaan);

            *jumlah_data++;

            printf("\n\nApakah anda akan menambahkan data lagi? [y/n]\n=>\t");
            char tanya;
            scanf("%c", &tanya);
            if (tanya == 'y' || tanya == 'Y')
            {
                size_t cek_data = fwrite(&isi_data, sizeof(KTP), 1, F_cuy);

                if (cek_data != 1)
                    printf("\n\n Data gagal ditambahkan, silakan lakukan kembali");
                else
                    system("clear");
            }
            else if (tanya == 'n' || tanya == 'N')
            {
                size_t cek_data = fwrite(&isi_data, sizeof(KTP), 1, F_cuy);

                if (cek_data != 1)
                    printf("\n\n Data gagal ditambahkan, silakan lakukan kembali");
                else
                    break;
            }
            else
            {
                printf("Saya anggap Anda tidak ingin menambahkan data\n");
                size_t cek_data = fwrite(&isi_data, sizeof(KTP), 1, F_cuy);

                if (cek_data != 1)
                    printf("\n\n Data gagal ditambahkan, silakan lakukan kembali");
                else
                    break;
            }
        }
    }
    fclose(F_cuy);
    printf ("\n\n");
}