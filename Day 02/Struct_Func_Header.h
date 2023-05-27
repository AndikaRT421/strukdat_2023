#include <stdio.h>
#include <stdlib.h>

typedef struct _KTP
{
    char NIK [20];
    char nama [100];
    char tempat_lahir [100];
    int tanggal, bulan, tahun;
    int kelamin;
    char alamat [100];
    int agama;
    char pekerjaan [100];
}KTP;

void menu();
void input_KTP(int *jumlah_data);
void load_KTP(int jumlah_data);
void hapus_KTP(int *jumlah_data);
void cari_KTP ();

