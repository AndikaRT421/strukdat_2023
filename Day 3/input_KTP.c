#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "Struct_Func_Header.h"

void input_KTP()
{
    system("clear");
    FILE *F_cuy = fopen("Data_KTP.bin", "ab+");

    if (F_cuy == NULL)
    {
        printf("Terjadi kesalahan. Tidak bisa input data KTP!\n");
    }
    else
    {
        while (1)
        {
            KTP isi_data;
            printf("\nSilakan masukkan NIK Anda:");
            printf("\n=>\t");
            scanf("%llu", &isi_data.NIK);

            printf("\nSilakan masukkan nama Anda:");
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.nama);

            printf("\nSilakan masukkan tempat kelahiran Anda:"); //tempat lahir
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.tempat_lahir);

            printf("\nSilakan masukkan tanggal, bulan, tahun kelahiram Anda:"); //Tanggal, bulan, tahun
            printf("\n[Contoh: 1-12-2002]");
            printf("\n=>\t");
            scanf("%d-%d-%d", &isi_data.tanggal, &isi_data.bulan, &isi_data.tahun);

            printf("\nSilakan masukkan jenis kelamin Anda:\t{1. Pria}\t{2. Wanita}"); // gender
            printf("\n[Cukup masukkan kode angkanya saja]");
            printf("\n=>\t");
            scanf("%d", &isi_data.kelamin);

            printf("\nSilakan masukkan alamat domisili Anda:"); // alamat domisili
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.alamat);

            printf("\nSilakan masukkan agama Anda:"); // agama
            printf("\n\t\t {1. Islam}\t{2. Kristen}\t{3. Katolik}");
            printf("\n\t\t {4. Hindu}\t{5. Buddha}\t{6. Konghuchu}");
            printf("\n[Cukup masukkan kode angkanya saja]");
            printf("\n=>\t");
            scanf("%d", &isi_data.agama);

            printf("\nSilakan masukkan jenis pekerjaan Anda:"); // pekerjaan
            printf("\n=>\t");
            scanf("\n%[^\n]%*c", &isi_data.pekerjaan);
            // banyak_data++; // nanti diganti ke int function
            size_t cek_data = fwrite(&isi_data, sizeof(KTP), 1, F_cuy);

            if (cek_data != 1)
                printf("\n\n Data gagal ditambahkan, silakan lakukan kembali\n");

            printf("\n\nApakah anda akan menambahkan data lagi? [y/n]\n=>\t");
            char tanya;
            scanf("%c", &tanya);
            if (tanya == 'n' || tanya == 'N')
            {
                break;
            }
        }
    }
    fclose(F_cuy);
    printf ("\n\n");
}