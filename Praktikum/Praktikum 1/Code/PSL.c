#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int bendera = 0;

/* Struktur Node */

typedef struct pqueueNode_t
{
    char nama[100];
    int umur, skala;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

// FUNGSINYA

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char name[], int usia, int scalee)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
    strcpy(newNode->nama, name);
    newNode->umur = usia;
    newNode->skala = scalee;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (scalee < pqueue->_top->skala)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
        return;
    }
    if (scalee == pqueue->_top->skala && usia > pqueue->_top->umur)
    {
        if (bendera == 0)
        {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
        }
        return;
    }
    if (scalee == pqueue->_top->skala && usia == pqueue->_top->umur)
    {
        // puts("ho");
        printf("Kamu jodoh ya %s - %d && %s - %d\n", pqueue->_top->nama, pqueue->_top->skala, name, scalee);
        bendera = 1;
    }
    else
    {
        while ((temp->next != NULL && temp->next->skala < scalee) || (temp->next != NULL && temp->next->skala == scalee && usia <= temp->next->umur))
        {
            if (temp->next->skala == scalee && temp->next->umur == usia)
            {
                printf("Kamu jodoh ya %s - %d && %s - %d\n", temp->next->nama, temp->next->skala, name, scalee);
                bendera = 1;
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top_skala(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->skala;
    else
        return 0;
}

int main()
{
    PriorityQueue pasien;
    pqueue_init(&pasien);
    int jumlah_pasien, jumlah_pop;
    scanf("%d %d", &jumlah_pasien, &jumlah_pop);

    if (jumlah_pasien == jumlah_pop)
    {
        printf("Full senyum deck\n");
        bendera = 1;
    }

    for (int i = 0; i < jumlah_pasien; i++)
    {
        char name[100];
        int usia, scallee;
        scanf("%s %d %d", &name, &usia, &scallee);

        if (bendera == 0)
        {
            pqueue_push(&pasien, name, usia, scallee);
        }
    }

    // while (!pqueue_isEmpty(&pasien))
    // {
    //     printf("%s %d\n", pasien._top->nama, pasien._top->skala);
    //     pqueue_pop(&pasien);
    // }

    for (int i = 0; i < jumlah_pop; i++)
    {
        pqueue_pop(&pasien);
    }
    if (bendera == 0)
    {
        printf("Pasien selanjutnya adalah: %s - %d\n", pasien._top->nama, pasien._top->skala);
    }
}