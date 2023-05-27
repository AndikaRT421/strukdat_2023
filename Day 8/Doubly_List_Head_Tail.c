#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TNode
{
    int data;
    struct TNode *next, *prev;
} TNode;

TNode *head, *tail;

void init()
{
    head = tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

void insertDepan(int value)
{
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    baru->data = value;
    baru->next = baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        head->next = head->prev = NULL;
        tail->next = tail->prev = NULL;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
        // tail->next = head; // test
        // head->prev = tail;
    }
}

void insertBelakang(int value)
{
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    baru->data = value;
    baru->next = baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        head->next = head->prev = NULL;
        tail->next = tail->prev = NULL;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void tampil_depan()
{
    TNode *bantu = (TNode *)malloc(sizeof(TNode));
    bantu = head;
    if (isEmpty() == 0)
    {
        while (bantu != tail->next)
        {
            printf("%d ", bantu->data);
            bantu = bantu->next;
        }
    }
    else
        printf("Data kosong\n");
}

void tampil_belakang()
{
    TNode *bantu = (TNode *)malloc(sizeof(TNode));
    bantu = tail;
    if (isEmpty() == 0)
    {
        while (bantu != head->prev)
        {
            printf("%d ", bantu->data);
            bantu = bantu->prev;
        }
    }
    else
        printf("Data kosong\n");
}

void clear()
{
    TNode *bantu = (TNode *)malloc(sizeof(TNode));
    bantu = head;
    while (bantu != NULL)
    {
        TNode *hapus = (TNode *)malloc(sizeof(TNode));
        hapus = bantu;
        bantu = bantu->next;
        free(hapus);
    }
    head = tail = NULL;
}

int main()
{
    init();
    insertDepan(3);
    insertDepan(2);
    insertDepan(1);
    insertBelakang(4);
    insertBelakang(5);

    tampil_depan();
    printf("\n");
    tampil_belakang();

    printf("\n");
    clear();
    tampil_depan();
    // printf("\n");
    tampil_belakang();
}