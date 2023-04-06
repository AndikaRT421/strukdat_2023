#include <iostream>
#include <stdlib.h>

using namespace std;
int jumlah_print = 0;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void __bst__preorder(BSTNode *root)
{
    if (root)
    {
        if (root->key % 2 != 0) 
        {
            cout << root->key << " ";
            jumlah_print++;
        }
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_preorder(BST *bst)
{
    __bst__preorder(bst->_root);
}

int main ()
{
    BST pohon;
    bst_init(&pohon);
    int banyak;
    cin >> banyak;
    while (banyak--)
    {
        int angka;
        cin >> angka;
        bst_insert(&pohon, angka);
    }
    bst_preorder(&pohon);
    cout << jumlah_print + 17 << endl;
}