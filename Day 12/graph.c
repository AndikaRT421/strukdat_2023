#include <stdio.h>
#include <stdlib.h>

struct tipeS
{
    struct tipeS *left;
    int INFO;
    struct tipeS *right;
};

typedef struct tipeS simpul;
simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;

simpul *PointS[5];

void main()
{
    int A[5][5] = {0, 5, 0, 2, 0, 6, 0, 3, 0, 0, 0, 0, 0, 0, 9, 0, 0, 12, 0, 7, 0, 14, 0, 0, 0};
    char NmS[5] = "ABCDE";
    int I, J;
    I = 0;
    J = 0;

    // Graph Init
    P = (simpul *)malloc(sizeof(simpul));
    P->INFO = NmS[0];
    FIRST = P;
    LAST = P;
    P->left = NULL;
    P->right = NULL;

    PointS[0] = P;
    printf("%c", P->INFO);
    printf(" alamat %d \n", PointS[0]);

    // Simpul Vertex dan selanjutnya
    for (I = 1; I <= 4; I++)
    {
        P = (simpul *)malloc(sizeof(simpul));
        P->INFO = NmS[I];
        LAST->left = P;
        LAST = LAST->left;
        P->left = NULL;
        P->right = NULL;
        PointS[I] = P;
        printf("%c", P->INFO);
        printf(" alamat %d \n", PointS[I]);
    }

    // Simpul Edge untuk semua Vertex
    Q = FIRST;
    for (I = 0; I <= 4; I++)
    {
        R = Q;
        printf("Vertex %c ... ", Q->INFO);

        for (J = 0; J <= 4; J++)
        {
            if (A[I][J] != 0)
            {
                P = (simpul *)malloc(sizeof(simpul));
                P->INFO = A[I][J];
                R->right = P;
                P->left = PointS[J];
                printf ("berhubungan dengan %c: ", P->left->INFO);
                printf(" bobot %d;", P->INFO);
                P->right = NULL;
                R = P;
            }
        }
        printf ("\n");
        Q = Q->left;
    }
}