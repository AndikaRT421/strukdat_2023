#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bstnode_t
{
    char nama[10002];
    struct bstnode_t *left, *right, *ortu;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
} BST;

BSTNode *__bst__createNode(char value[])
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    strcpy(newNode->nama, value);
    newNode->ortu = NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, char value[])
{
    if (root == NULL)
        return __bst__createNode(value);

    if (strcmp(root->nama, value) < 0)
    {
        root->left = __bst__insert(root->left, value);
        root->left->ortu = root;
    }
    else if (strcmp(root->nama, value) > 0)
    {
        root->right = __bst__insert(root->right, value);
        root->right->ortu = root;
    }
    return root;
}

BSTNode *__bst__search_ibu(BSTNode *root, char value[])
{
    if (strcmp(root->nama, value) == 0)
    {
        if (root->ortu->nama == NULL)
            printf("Aku Adalah Pemimpin Keluarga Ini! HAHAHA\n");
        else
            printf("%s\n", root->ortu->nama);
    }

    if (strcmp(root->nama, value) < 0)
    {
        // root->ortu = root;
        root->left = __bst__search_ibu(root->left, value);
    }
    else if (strcmp(root->nama, value) > 0)
    {
        root->right = __bst__search_ibu(root->right, value);
    }
    return root;
}

BSTNode *__bst__search_anak(BSTNode *root, char value[])
{
    if (strcmp(root->nama, value) == 0)
    {
        int tanda = 0;
        if (root->left->nama != NULL)
            tanda++;
        if (root->right->nama != NULL)
            tanda += 2;

        if (tanda == 0)
            printf("Aku Sedih!! Tidak Memiliki Anak:)\n");
        else if (tanda == 1)
            printf("%s -\n", root->left->nama);
        else if (tanda == 2)
            printf("- %s\n", root->right->nama);
        else if (tanda == 3)
            printf("%s %s\n", root->left->nama, root->right->nama);
    }

    if (strcmp(root->nama, value) < 0)
    {
        root->left = __bst__search_anak(root->left, value);
    }
    else if (strcmp(root->nama, value) > 0)
    {
        root->right = __bst__search_anak(root->right, value);
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    // bst->_root->ortu = NULL;
}

void bst_insert(BST *bst, char value[])
{
    bst->_root = __bst__insert(bst->_root, value);
}

void bst_find_ibu(BST *bst, char value[])
{
    BSTNode *temp = __bst__search_ibu(bst->_root, value);
    if (temp->nama)
        return;
    else
        return;
}

void bst_find_anak(BST *bst, char value[])
{
    BSTNode *temp = __bst__search_anak(bst->_root, value);
    if (temp->nama)
        return;
    else
        return;
}

int main()
{
    BST pohon;
    bst_init(&pohon);
    int N, TC;
    scanf("%d %d", &N, &TC);
    while (N--)
    {
        char value[10002];
        scanf("%s", value);
        bst_insert(&pohon, value);
    }
    while (TC--)
    {
        char perintah[10], nama[10002];
        scanf("%s %s", perintah, nama);
        if (!strcmp(perintah, "Ibu"))
        {
            bst_find_ibu(&pohon, nama);
        }
        else if (!strcmp(perintah, "Anak"))
        {
            bst_find_anak(&pohon, nama);
        }
    }
}