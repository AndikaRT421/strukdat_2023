#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *kiri;
    struct node *kanan;
    int tinggi;
};

struct node *akar = NULL;

struct node *buatNode(int);
struct node *sisip(struct node *, int);
struct node *hapus(struct node *, int);
struct node *cari(struct node *, int);
struct node *putarKiri(struct node *);
struct node *putarKanan(struct node *);
int faktorSeimbang(struct node *);
int tinggi(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

int main()
{
    int pilihanPengguna, data;
    char lanjutkan = 'y';
    struct node *hasil = NULL;

    while (lanjutkan == 'y' || lanjutkan == 'Y')
    {
        printf("\n\n------- TREE AVL --------\n");
        printf("\n1. Sisip");
        printf("\n2. Hapus");
        printf("\n3. Cari");
        printf("\n4. Inorder");
        printf("\n5. Preorder");
        printf("\n6. Postorder");
        printf("\n7. KELUAR");

        printf("\n\nMasukkan Pilihan Anda: ");
        scanf("%d", &pilihanPengguna);

        switch (pilihanPengguna)
        {
        case 1:
            printf("\nMasukkan data: ");
            scanf("%d", &data);
            akar = sisip(akar, data);
            break;

        case 2:
            printf("\nMasukkan data: ");
            scanf("%d", &data);
            akar = hapus(akar, data);
            break;

        case 3:
            printf("\nMasukkan data: ");
            scanf("%d", &data);
            hasil = cari(akar, data);
            if (hasil == NULL)
            {
                printf("\nNode tidak ditemukan!");
            }
            else
            {
                printf("\nNode ditemukan");
            }
            break;
        case 4:
            inorder(akar);
            break;

        case 5:
            preorder(akar);
            break;

        case 6:
            postorder(akar);
            break;

        case 7:
            printf("\n\tProgram Terminated\n");
            return 1;

        default:
            printf("\n\tPilihan Tidak Valid\n");
        }

        printf("\n\nApakah Anda ingin melanjutkan? ");
        scanf(" %c", &lanjutkan);
    }

    return 0;
}

struct node *buatNode(int data)
{
    struct node *nodeBaru = (struct node *)malloc(sizeof(struct node));

    if (nodeBaru == NULL)
    {
        printf("\nMemori tidak dapat dialokasikan\n");
        return NULL;
    }
    nodeBaru->data = data;
    nodeBaru->kiri = NULL;
    nodeBaru->kanan = NULL;
    return nodeBaru;
}

struct node *putarKiri(struct node *akar)
{
    struct node *anakKanan = akar->kanan;
    akar->kanan = anakKanan->kiri;
    anakKanan->kiri = akar;

    akar->tinggi = tinggi(akar);
    anakKanan->tinggi = tinggi(anakKanan);

    return anakKanan;
}

struct node *putarKanan(struct node *akar)
{
    struct node *anakKiri = akar->kiri;
    akar->kiri = anakKiri->kanan;
    anakKiri->kanan = akar;

    akar->tinggi = tinggi(akar);
    anakKiri->tinggi = tinggi(anakKiri);

    return anakKiri;
}

int faktorSeimbang(struct node *akar)
{
    int lh, rh;
    if (akar == NULL)
        return 0;
    if (akar->kiri == NULL)
        lh = 0;
    else
        lh = 1 + akar->kiri->tinggi;
    if (akar->kanan == NULL)
        rh = 0;
    else
        rh = 1 + akar->kanan->tinggi;
    return lh - rh;
}

int tinggi(struct node *akar)
{
    int lh, rh;
    if (akar == NULL)
    {
        return 0;
    }
    if (akar->kiri == NULL)
        lh = 0;
    else
        lh = 1 + akar->kiri->tinggi;
    if (akar->kanan == NULL)
        rh = 0;
    else
        rh = 1 + akar->kanan->tinggi;

    if (lh > rh)
        return (lh);
    return (rh);
}

struct node *sisip(struct node *akar, int data)
{
    if (akar == NULL)
    {
        struct node *nodeBaru = buatNode(data);
        if (nodeBaru == NULL)
        {
            return NULL;
        }
        akar = nodeBaru;
    }
    else if (data > akar->data)
    {
        akar->kanan = sisip(akar->kanan, data);

        if (faktorSeimbang(akar) == -2)
        {
            if (data > akar->kanan->data)
            {
                akar = putarKiri(akar);
            }
            else
            {
                akar->kanan = putarKanan(akar->kanan);
                akar = putarKiri(akar);
            }
        }
    }
    else
    {
        akar->kiri = sisip(akar->kiri, data);

        if (faktorSeimbang(akar) == 2)
        {
            if (data < akar->kiri->data)
            {
                akar = putarKanan(akar);
            }
            else
            {
                akar->kiri = putarKiri(akar->kiri);
                akar = putarKanan(akar);
            }
        }
    }
    akar->tinggi = tinggi(akar);
    return akar;
}

struct node *hapus(struct node *akar, int x)
{
    struct node *temp = NULL;

    if (akar == NULL)
    {
        return NULL;
    }

    if (x > akar->data)
    {
        akar->kanan = hapus(akar->kanan, x);
        if (faktorSeimbang(akar) == 2)
        {
            if (faktorSeimbang(akar->kiri) >= 0)
            {
                akar = putarKanan(akar);
            }
            else
            {
                akar->kiri = putarKiri(akar->kiri);
                akar = putarKanan(akar);
            }
        }
    }
    else if (x < akar->data)
    {
        akar->kiri = hapus(akar->kiri, x);
        if (faktorSeimbang(akar) == -2)
        {
            if (faktorSeimbang(akar->kanan) <= 0)
            {
                akar = putarKiri(akar);
            }
            else
            {
                akar->kanan = putarKanan(akar->kanan);
                akar = putarKiri(akar);
            }
        }
    }
    else
    {
        if (akar->kanan != NULL)
        {
            temp = akar->kanan;
            while (temp->kiri != NULL)
                temp = temp->kiri;

            akar->data = temp->data;
            akar->kanan = hapus(akar->kanan, temp->data);
            if (faktorSeimbang(akar) == 2)
            {
                if (faktorSeimbang(akar->kiri) >= 0)
                {
                    akar = putarKanan(akar);
                }
                else
                {
                    akar->kiri = putarKiri(akar->kiri);
                    akar = putarKanan(akar);
                }
            }
        }
        else
        {
            return (akar->kiri);
        }
    }
    akar->tinggi = tinggi(akar);
    return (akar);
}

struct node *cari(struct node *akar, int key)
{
    if (akar == NULL)
    {
        return NULL;
    }

    if (akar->data == key)
    {
        return akar;
    }

    if (key > akar->data)
    {
        cari(akar->kanan, key);
    }
    else
    {
        cari(akar->kiri, key);
    }
}

// penelusuran inorder pada pohon
void inorder(struct node *akar)
{
    if (akar == NULL)
    {
        return;
    }

    inorder(akar->kiri);
    printf("%d ", akar->data);
    inorder(akar->kanan);
}

// penelusuran preorder pada pohon
void preorder(struct node *akar)
{
    if (akar == NULL)
    {
        return;
    }

    printf("%d ", akar->data);
    preorder(akar->kiri);
    preorder(akar->kanan);
}

// penelusuran postorder pada pohon
void postorder(struct node *akar)
{
    if (akar == NULL)
    {
        return;
    }

    postorder(akar->kiri);
    postorder(akar->kanan);
    printf("%d ", akar->data);
}
