#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct snode_t
{
    int angka;
    struct snode_t *next;
} Slistnode;

typedef struct slist_t
{
    Slistnode *head;
    Slistnode *tail;
} SinglyNode;

void init(SinglyNode *SLLNC)
{
    SLLNC->head = NULL;
    SLLNC->tail = NULL;
}

bool is_empty(SinglyNode *SLLNC)
{
    if (SLLNC->tail == NULL)
        return true;
    else
        return false;
}

void push_front(SinglyNode *SLLNC, int value)
{
    Slistnode *temp = (Slistnode *)malloc(sizeof(Slistnode));
    if (temp)
    {
        temp->angka = value;
        temp->next = NULL;
        if (is_empty(SLLNC))
        {
            SLLNC->head = SLLNC->tail = temp;
            SLLNC->tail->next = NULL;
        }
        else
        {
            temp->next = SLLNC->head;
            SLLNC->head = temp;
        }
    }
    printf("Data masuk\n");
}

void push_back(SinglyNode *SLLNC, int value)
{
    Slistnode *temp = (Slistnode *)malloc(sizeof(Slistnode));
    if (temp)
    {
        temp->angka = value;
        temp->next = NULL;
        if (is_empty(SLLNC))
        {
            SLLNC->tail = SLLNC->head = temp;
            SLLNC->tail->next = NULL;
        }
        else
        {
            SLLNC->tail->next = temp;
            SLLNC->tail = temp;
        }
    }
    printf("Data masuk\n");
}

void pop_front(SinglyNode *SLLNC)
{
    Slistnode *temp = (Slistnode *)malloc(sizeof(Slistnode));
    if (!is_empty(SLLNC))
    {
        if (SLLNC->head != SLLNC->tail)
        {
            temp = SLLNC->head;
            SLLNC->head = SLLNC->head->next;
            free(temp);
        }
        else
        {
            SLLNC->head = NULL;
            SLLNC->tail = NULL;
        }
        printf("Data telah terhapus\n");
    }
    else
        printf("List kosong\n");
}

void pop_back(SinglyNode *SLLNC)
{
    Slistnode *bantu = (Slistnode *)malloc(sizeof(Slistnode));
    Slistnode *hapus = (Slistnode *)malloc(sizeof(Slistnode));

    if (!is_empty(SLLNC))
    {
        bantu = SLLNC->head;
        if (SLLNC->head != SLLNC->tail)
        {
            while (bantu->next != SLLNC->tail)
            {
                bantu = bantu->next;
            }
            hapus = SLLNC->tail;
            SLLNC->tail = bantu;
            free(hapus);
            SLLNC->tail->next = NULL;
        }
        else
        {
            SLLNC->head = SLLNC->tail = NULL;
        }
        printf("Data telah terhapus\n");
    }
    else
        printf("List kosong\n");
}

void tampil(SinglyNode *SLLNC)
{
    Slistnode *temp = (Slistnode *)malloc(sizeof(Slistnode));
    temp = SLLNC->head;
    if (!is_empty(SLLNC))
    {
        while (temp != NULL)
        {
            printf("%d ", temp->angka);
            temp = temp->next;
        }
        printf("\n");
    }
    else
        printf("List Kosong\n");
}

void menu()
{
    // Your code goes here
    printf("\t\t\t#############################\n");
    printf("\t\t\t||\tHALAMAN UTAMA      ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[1.]\tTambah Depan\t   ||\t\t\n");
    printf("\t\t\t[2.]\tTambah Belakang\t   ||\t\t\n");
    printf("\t\t\t[3.]\tHapus Depan\t   ||\t\t\n");
    printf("\t\t\t[4.]\tHapus Belakang\t   ||\t\t\n");
    printf("\t\t\t[5.]\tTampilkan Data\t   ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[0.]\tEXIT\t\t   ||\t\t\n");

    printf("\t\t\t#############################\n");

    printf("\n\n Silakan masukkan kode angka sesuai menu: ");
    // return 0;
}

int main()
{
    SinglyNode SLLNC;
    init(&SLLNC);
    int perintah;
    menu();
    scanf("%d", &perintah);
    while (perintah != 0)
    {
        if (perintah == 1)
        {
            int angka;
            printf("Silakan masukkan angka: ");
            scanf("%d", &angka);
            push_front(&SLLNC, angka);
        }
        else if (perintah == 2)
        {
            int angka;
            printf("Silakan masukkan angka: ");
            scanf("%d", &angka);
            push_back(&SLLNC, angka);
        }
        else if (perintah == 3)
        {
            pop_front(&SLLNC);
        }
        else if (perintah == 4)
        {
            pop_back(&SLLNC);
        }
        else if (perintah == 5)
        {
            tampil(&SLLNC);
        }
        menu();
        scanf("%d", &perintah);
    }
}