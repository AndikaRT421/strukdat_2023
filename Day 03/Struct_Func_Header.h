#include <stdio.h>
#include <stdlib.h>

typedef struct _KTP
{
    long long NIK;
    char nama [100];
    char tempat_lahir [100];
    int tanggal, bulan, tahun;
    int kelamin;
    char alamat [100];
    int agama;
    char pekerjaan [100];
}KTP;

void menu();
void input_KTP();
void cari_KTP();
int banding(const void *a, const void *b);
int Inter_Search(KTP data[], long long loww, long long highh, long long kunci);
