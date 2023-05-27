#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *left, *right;
} Tree;

int isEmpty(Tree *pohon)
{
    if (pohon == NULL)
        return 1;
    else
        return 0;
}

void tambah(Tree **root, int databaru)
{
    if ((*root) == NULL)
    {
        Tree *baru;
        baru = (Tree *)malloc(sizeof(Tree));
        baru->data = databaru;
        baru->left = baru->right = NULL;
        (*root) = baru;
        // (*root)->left = NULL;
        // (*root)->right = NULL;
        // free(baru);
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->left, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->right, databaru);
    else
        printf("Data sudah ada !\n");
}

void preOrder(Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Tree *cari(Tree *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        return (cari(root->left, data));
    else if (data > root->data)
        return (cari(root->right, data));
    else
        return root;
}

int count(Tree *root)
{
    if (root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int height(Tree *root)
{
    if (root == NULL)
        return -1;
    int u = height(root->left), v = height(root->right);

    if (u > v)
        return u + 1;
    else
        return v + 1;
}

Tree *FindMin(Tree *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (root->left == NULL)
            return root;
        else
            return FindMin(root->left);
    }
}

Tree *FindMax(Tree *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (root->right == NULL)
            return root;
        else
            return FindMax(root->right);
    }
}

void leaf(Tree *root)
{
    if (root == NULL)
        printf("Kosong!\n");
    if (root->left != NULL)
        leaf(root->left);
    if (root->right != NULL)
        leaf(root->right);
    if (root->right == NULL && root->left == NULL)
        printf("%d ", root->data);
}

void hapus(Tree **root, int value)
{
    if ((*root) == NULL)
    {
        printf("Sudah Kosong\n");
        return;
    }
    else
    {
        if (value > (*root)->data)
            hapus(&(*root)->right, value);
        else if (value < (*root)->data)
            hapus(&(*root)->data, value);
        else
        {
            if ((*root)->left == NULL)
            {
                Tree *rightChild = (*root)->right;
                free(*root);
                *root = rightChild;
            }
            else if ((*root)->right == NULL)
            {
                Tree *temp = (*root)->left;
                free(*root);
                *root = temp;
            }
            else
            {
                Tree *temp = FindMin((*root)->right);
                (*root)->data = temp->data;
                hapus(&(*root)->right, temp->data);
            }
        }
    }
}

void menu()
{
    // Your code goes here
    printf("\n");
    printf("\t\t\t#############################\n");
    printf("\t\t\t||\tHALAMAN UTAMA      ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[1.]\tInput Data Tree\t\t   ||\t\t\n");
    printf("\t\t\t[2.]\tCek Data Tree\t\t   ||\t\t\n");
    printf("\t\t\t[3.]\tTransverse Preorder\t   ||\t\t\n");
    printf("\t\t\t[4.]\tTransverse Inorder\t   ||\t\t\n");
    printf("\t\t\t[5.]\tTransverse Postorder\t   ||\t\t\n");
    printf("\t\t\t[6.]\tHitung jumlah node\t   ||\t\t\n");
    printf("\t\t\t[7.]\tHitung kedalaman Tree\t   ||\t\t\n");
    printf("\t\t\t[8.]\tNilai terkecil Tree\t   ||\t\t\n");
    printf("\t\t\t[9.]\tNilai terbesar Tree\t   ||\t\t\n");
    printf("\t\t\t[10.]\tKondisi leaf Tree\t   ||\t\t\n");
    printf("\t\t\t[11.]\tHapus node Tree\t   ||\t\t\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\t[0.]\tEXIT\t\t   ||\t\t\n");

    printf("\t\t\t#############################\n");

    printf("\n\n Silakan masukkan kode angka sesuai menu : ");
    // return 0;
}

int main()
{
    Tree *pohon;
    pohon = NULL;

    menu();
    int perintah;
    scanf("%d", &perintah);
    while (perintah != 0)
    {
        system("cls");
        if (perintah == 1)
        {
            int data;
            printf("\nMasukkan Data : ");
            scanf("%d", &data);
            tambah(&pohon, data);
            printf("\nData telah ditambahkan\n");
        }
        else if (perintah == 2)
        {
            int data;
            printf("\nMasukkan Data : ");
            scanf("%d", &data);
            if (cari(pohon, data))
                printf("Data ada pada Tree\n");
            else
                printf("Data tidak ada pada Tree");
        }
        else if (perintah == 3)
        {
            printf("\nPreorder : ");
            preOrder(pohon);
        }
        else if (perintah == 4)
        {
            printf("\nInorder : ");
            inOrder(pohon);
        }
        else if (perintah == 5)
        {
            printf("\nPostorder : ");
            postOrder(pohon);
        }
        else if (perintah == 6)
        {
            printf("\nJumlah node pada Tree : %d\n", count(pohon));
        }
        else if (perintah == 7)
        {
            printf("\nKedalaman Tree : %d\n", height(pohon));
        }
        else if (perintah == 8)
        {
            int terkecil = FindMin(pohon)->data;
            printf("\nData terkecil dari Tree adalah : %d\n", terkecil);
        }
        else if (perintah == 9)
        {
            int terbesar = FindMax(pohon)->data;
            printf("\nData terkecil dari Tree adalah : %d\n", terbesar);
        }
        else if (perintah == 10)
        {
            printf("\nKondisi leaf pada Tree: ");
            leaf(pohon);
        }
        else if (perintah == 11)
        {
            int data;
            printf("\nMasukkan Data : ");
            scanf("%d", &data);
            hapus(&pohon, data);
            printf("\nData telah terhapus\n");
        }
        menu();
        scanf("%d", &perintah);
    }
    printf("\nTerima Kasih\n");
}
