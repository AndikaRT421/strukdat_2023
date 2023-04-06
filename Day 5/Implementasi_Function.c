#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void menu();
int faktorial(int x);
int power_by(int x, int y);
void prime_checker(int x);
void banyak_prima(int x);
void prime_range(int n);

int main()
{
    printf("\n\n");
    printf("\t\t\t*****************************\n");
    printf("\t\t\t**\tSELAMAT DATANG     **\t\t\n");
    menu();
    int perintah;
    scanf("%d", &perintah);

    while (perintah != 0)
    {
        if (perintah == 1)
        {
            system("clear");

            printf("Silakan masukkan angka faktorial: ");
            int angka;
            scanf("%d", &angka);

            printf("Faktorial dari %d = %d\n", angka, faktorial(angka));
        }
        else if (perintah == 2)
        {
            system("clear");

            printf("Silakan masukkan angka yang akan dipangkatkan (base): ");
            int angka;
            scanf("%d", &angka);

            printf("Silakan masukkan angka yang menjadi pangkat: ");
            int pangkat;
            scanf("%d", &pangkat);

            printf("Hasil %d^%d = %d\n", angka, pangkat, power_by(angka, pangkat));
        }
        else if (perintah == 3)
        {
            system("clear");

            printf("Silakan masukkan angka yang akan diperiksa: ");
            int angka;
            scanf("%d", &angka);

            prime_checker(angka);
        }
        else if (perintah == 4)
        {
            system("clear");

            printf("Silakan masukkan banyak angka prima pertama yang diinginkan: ");
            int angka;
            scanf("%d", &angka);

            banyak_prima(angka);
        }
        else if (perintah == 5)
        {
            system("clear");

            printf("Silakan masukkan batas angka prima: ");
            int angka;
            scanf("%d", &angka);

            prime_range(angka);
        }
        printf("\n");
        menu();
        scanf("%d", &perintah);
    }
    return 0;
}

void menu()
{
    // Your code goes here
    printf("\t\t\t#############################\n");
    printf("\t\t\t||\tHALAMAN UTAMA      ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[1.]\tFaktorial\t   ||\t\t\n");
    printf("\t\t\t[2.]\tPerpangkatan\t   ||\t\t\n");
    printf("\t\t\t[3.]\tCek Prima\t   ||\t\t\n");
    printf("\t\t\t[4.]\tBanyak Prima\t   ||\t\t\n");
    printf("\t\t\t[5.]\tJangkauan Prima\t   ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[0.]\tEXIT\t\t   ||\t\t\n");

    printf("\t\t\t#############################\n");

    printf("\n\nSilakan masukkan kode angka sesuai menu:\n");
    printf("=> ");
    // return 0;
}

int faktorial(int x)
{
    int hasil = x;
    for (int i = x - 1; i > 0; i--)
    {
        hasil *= i;
    }
    return hasil;
}

int power_by(int x, int y)
{
    int hasil = x;
    for (int i = 1; i < y; i++)
    {
        hasil *= x;
    }
    return hasil;
}

void prime_checker(int x)
{
    int flag = 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (x <= 1)
        flag = 1;

    if (flag == 0)
        printf("%d adalah bilangan prima\n", x);
    else
        printf("%d bukan bilangan prima\n", x);
}

void banyak_prima(int x)
{
    printf("\nBerikut ini %d pertama bilangan prima:\n\n", x);
    int banyak_prima = 0;
    for (int num = 2; banyak_prima < x; num++)
    {
        int flag = 0;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d ", num);
            banyak_prima++;
        }
    }
    printf("\n\n");
}

void prime_range(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            printf("%d ", p);

    printf("\n\n");
}
