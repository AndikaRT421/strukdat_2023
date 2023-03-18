#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Mahasiswa
{
    int nim;
    char nama[100];
    struct Mahasiswa *next;
};

void init(struct Mahasiswa **p)
{
    *p = NULL;
}

struct Mahasiswa *alokasi(int nim, char name[])
{
    struct Mahasiswa *p;
    p = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    if (p != NULL)
    {
        p->next = NULL;
        p->nim = nim;
        strcpy(p->nama, name);
    }
    return (p);
}

void Add(struct Mahasiswa **p, int nim, char name[])
{
    *p = alokasi(nim, name);
    printf("%d ", (*p)->nim);
    printf("%s ", (*p)->nama);
}

int main()
{
    struct Mahasiswa *head;
    init(&head);
    int banyak_data;
    scanf ("%d", &banyak_data);
    for (int i = 0; i < banyak_data; i++)
    {
        int NIM;
        char jeneng[100];
        scanf("%d %s", &NIM, &jeneng);
        Add(&head, NIM, jeneng);
        printf ("\n\n");
        // getch();
    }
}