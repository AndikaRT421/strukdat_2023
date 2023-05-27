#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dt_KTP
{
    struct Dt_KTP *left, *right;
    char nama[20], ID[20], status[20];
    int umur;
    int INFO;
};

typedef struct Dt_KTP Data_KTP;
Data_KTP *FIRST = NULL, *LAST = NULL;
Data_KTP *P, *Q, *R;

int total_data = 0;
int capacity_points = 100;
Data_KTP **PointS;

void increase_capacity()
{
    capacity_points *= 2;
    PointS = (Data_KTP **)realloc(PointS, capacity_points * sizeof(Data_KTP *));
    if (PointS == NULL)
    {
        printf("\nGagal mengalokasikan ulang PointS !\n");
        exit(1);
    }
}

void menu()
{
    printf("\t\t\t#############################\n");
    printf("\t\t\t||\tHALAMAN UTAMA      ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[1.]\tInput Data KTP\t   ||\t\t\n");
    printf("\t\t\t[2.]\tRelasi Data KTP\t   ||\t\t\n");
    printf("\t\t\t[3.]\tLoad Data KTP\t   ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[0.]\tEXIT\t\t   ||\t\t\n");
    printf("\t\t\t#############################\n");

    printf("\n\n Silakan masukkan kode angka sesuai menu: ");
}

void input_data(char nama[], char ID[], char status[], int umur)
{
    FILE *F_cuy = fopen("Data_KTP.bin", "ab+");

    if (F_cuy == NULL)
    {
        printf("Terjadi kesalahan. Tidak bisa input KTP!\n");
    }
    else
    {
        P = (Data_KTP *)malloc(sizeof(Data_KTP));
        P->umur = umur;
        strcpy(P->nama, nama);
        strcpy(P->ID, ID);
        strcpy(P->status, status);

        if (FIRST == NULL && LAST == NULL && total_data == 0)
        {
            FIRST = P;
            LAST = P;
        }
        else
        {
            LAST->left = P;
            LAST = LAST->left;
        }

        P->left = NULL;
        P->right = NULL;

        if (total_data >= capacity_points)
        {
            increase_capacity();
        }

        PointS[total_data] = P;
        printf("\n%s", P->ID);
        printf(" alamat %p \n", (void *)PointS[total_data]);
        total_data++;

        size_t cek_data = fwrite(P, sizeof(Data_KTP), 1, F_cuy);

        if (cek_data != 1)
            printf("\nData gagal ditambahkan, silakan lakukan kembali");
        else
            printf("\nData berhasil ditambahkan !\n");

        fclose(F_cuy);
    }
}

void load_data()
{
    FILE *F_cuy = fopen("Data_KTP.bin", "rb");

    if (F_cuy == NULL)
    {
        printf("Terjadi kesalahan. Tidak dapat membuka file Data_KTP.bin!\n");
    }
    else
    {
        Data_KTP temp;

        while (fread(&temp, sizeof(Data_KTP), 1, F_cuy) == 1)
        {
            P = (Data_KTP *)malloc(sizeof(Data_KTP));
            P->umur = temp.umur;
            strcpy(P->nama, temp.nama);
            strcpy(P->ID, temp.ID);
            strcpy(P->status, temp.status);

            if (FIRST == NULL && LAST == NULL && total_data == 0)
            {
                FIRST = P;
                LAST = P;
            }
            else
            {
                LAST->left = P;
                LAST = LAST->left;
            }

            P->left = NULL;
            P->right = NULL;

            if (total_data >= capacity_points)
            {
                increase_capacity();
            }

            PointS[total_data] = P;
            printf("\nID: %s", P->ID);
            printf(" alamat %p \n", (void *)PointS[total_data]);
            total_data++;
        }

        printf("\nData berhasil dimuat dari file Data_KTP.bin!\n");

        fclose(F_cuy);
    }
}

int main()
{
    PointS = (Data_KTP **)malloc(capacity_points * sizeof(Data_KTP *));
    if (PointS == NULL)
    {
        printf("Terjadi kesalahan. Gagal mengalokasikan memori!");
        return 1;
    }
    menu();
    int perintah;
    scanf("%d", &perintah);
    while (perintah != 0)
    {
        if (perintah == 1)
        {
            char nama[20], status[20], ID[20];
            int umur;
            printf("\nMasukkan ID: ");
            scanf("%s", ID);
            printf("\nMasukkan nama: ");
            scanf("%s", nama);
            printf("\nMasukkan usia: ");
            scanf("%d", &umur);
            printf("\nMasukkan status: ");
            scanf("%s", status);

            input_data(nama, ID, status, umur);
        }
        else if (perintah == 2)
        {
            printf("Masukkan weight antar relasi:\n");
            int relasi[total_data][total_data];
            for (int i = 0; i < total_data; i++)
            {
                for (int j = 0; j < total_data; j++)
                {
                    int weight;
                    scanf("%d", &weight);
                    relasi[i][j] = weight;
                }
            }
            printf("\n\n");

            Q = FIRST;
            for (int i = 0; i < total_data; i++)
            {
                R = Q;
                printf("\n-----------------------------------\n");
                printf("ID\t\t: %s\n", Q->ID);
                printf("Nama\t\t: %s\n", Q->nama);
                printf("Umur\t\t: %d\n", Q->umur);
                printf("Status\t\t: %s\n", Q->status);
                printf("....\n");

                for (int j = 0; j < total_data; j++)
                {
                    if (relasi[i][j] != 0)
                    {
                        P = (Data_KTP *)malloc(sizeof(Data_KTP));
                        P->INFO = relasi[i][j];
                        R->right = P;
                        P->left = PointS[j];
                        printf("\nberhubungan dengan %s: relasi = %d\n", P->left->nama, P->INFO);
                        P->right = NULL;
                        R = P;
                    }
                }
                printf("\n");
                Q = Q->left;
            }
        }
        else if (perintah == 3)
        {
            load_data();
        }
        menu();
        scanf("%d", &perintah);
    }
    free (PointS);
    return 0;
}
