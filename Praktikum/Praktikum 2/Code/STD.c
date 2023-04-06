#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstnode_t
{
    struct bstnode_t *left, *right;
    int ruangan, monster;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
} BST;

BSTNode *__bst__createNode(int room, int monsterr)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->ruangan = room;
    newNode->monster = monsterr;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int room, int monsterr)
{
    if (root == NULL)
        return __bst__createNode(room, monsterr);

    if (room < root->ruangan)
    {
        root->left = __bst__insert(root->left, room, monsterr);
    }
    else if (room > root->ruangan)
    {
        root->right = __bst__insert(root->right, room, monsterr);
    }
    return root;
}

BSTNode *__bst__ancestor(BSTNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->ruangan == n1 || root->ruangan == n2)
        return root;

    BSTNode *kiri_ancestor = __bst__ancestor(root->left, n1, n2);
    BSTNode *kanan_ancestor = __bst__ancestor(root->right, n1, n2);

    if (kiri_ancestor && kanan_ancestor)
        return root;

    return (kiri_ancestor != NULL) ? kiri_ancestor : kanan_ancestor;
}

// PRIMARY FUNC

void bst_init(BST *bst)
{
    bst->_root = NULL;
}

void bst_insert(BST *bst, int room, int monsterr)
{
    bst->_root = __bst__insert(bst->_root, room, monsterr);
}

void bst_search(BSTNode *root, int room, int *stamina)
{
    while (root != NULL)
    {
        if (room < root->ruangan)
        {
            *stamina += root->monster + 1;
            root = root->left;
        }
        else if (room > root->ruangan)
        {
            *stamina += root->monster + 1;
            root = root->right;
        }
        else
        {
            *stamina += root->monster;
            return;
        }
    }
}

void hitung_energi(BST *bst, int n1, int n2)
{
    BSTNode *ancestor = __bst__ancestor(bst->_root, n1, n2);
    int stamina = 0;
    bst_search(ancestor, n1, &stamina);
    bst_search(ancestor, n2, &stamina);
    printf ("%d\n", stamina - ancestor->monster);
}

int main ()
{
    BST pohon;
    bst_init (&pohon);
    int n1, n2;
    scanf ("%d %d", &n1, &n2);

    int total_ruangan;
    scanf("%d", &total_ruangan);
    while (total_ruangan--)
    {
        int room, monsterr;
        scanf ("%d %d", &room, &monsterr);
        bst_insert(&pohon, room, monsterr);
    }
    hitung_energi (&pohon, n1, n2);
}