#include <iostream>

using namespace std;

int N, Q, jumlah_soal;
// int mboh = 0;
// int mboh2 = 0;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right, *ortu;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    int size;
} BST;

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = newNode->ortu = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
    {
        root->left = __bst__insert(root->left, value);
        root->left->ortu = root;
    }
    else if (value > root->key)
    {
        root->right = __bst__insert(root->right, value);
        root->right->ortu = root;
    }
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

BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *__bst__findMaxNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->right != NULL)
        currNode = currNode->right;

    return currNode;
}

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->size = 0;
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
        bst->size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->size--;
    }
}

void SemuaLeaves(BSTNode *pohon, BST *daun)
{
    if (pohon == NULL)
        return;
    if (pohon->left == NULL && pohon->right == NULL)
    {
        bst_insert(daun, pohon->key);
        // mboh2++;
        return;
    }
    SemuaLeaves(pohon->left, daun);
    SemuaLeaves(pohon->right, daun);
}

BSTNode *findSuccessor(BSTNode *node)
{
    if (node->right != NULL)
        return __bst__findMinNode(node->right);
    BSTNode *NODEortu = node->ortu;
    while (NODEortu != NULL && node == NODEortu->right)
    {
        node = NODEortu;
        NODEortu = NODEortu->ortu;
    }
    return NODEortu;
}

BSTNode *findPredecessor(BSTNode *node)
{
    if (node->left != NULL)
        return __bst__findMaxNode(node->left);
    BSTNode *NODEortu = node->ortu;
    while (NODEortu != NULL && node == NODEortu->left)
    {
        node = NODEortu;
        NODEortu = NODEortu->ortu;
    }
    return NODEortu;
}

void pasangan (BST *pohon, BSTNode *root, int target, int *flag, int *temp)
{
    if(root != NULL)
    {
        if (bst_find(pohon, target - root->key) && (target - root->key != root->key))
        {
            *flag = 0;
            *temp = min(root->key, *temp);
        }
        if (target - root->key > 0) pasangan (pohon, root->right, target, flag, temp);
        pasangan (pohon, root->left, target, flag, temp);
    }
}

void __bst__inorder(BSTNode *root, BST *leaf, int mboh)
{
    if (root)
    {
        __bst__inorder(root->left, leaf, mboh);
        printf("%d", root->key);
        mboh++;
        if (mboh < leaf->size)
        {
        	printf(", ");
        }
        __bst__inorder(root->right, leaf, mboh);
    }
}

void bst_inorder(BST *bst, int mboh)
{
    __bst__inorder(bst->_root, bst, mboh);
}



int main()
{
    BST pohon, daun;
    bst_init(&pohon);
    bst_init(&daun);
    scanf("%d", &N);
    jumlah_soal = N;
    while (N--)
    {
        int A;
        scanf("%d", &A);
        bst_insert(&pohon, A);
    }
    SemuaLeaves(pohon._root, &daun);
    scanf("%d", &Q);
    int mboh = 0;
    while (Q--)
    {
        int X;
        scanf("%d", &X);
        int flag = 1;
        int temp = 1000000004;
        pasangan (&pohon, pohon._root, X, &flag, &temp);
        if (flag == 1)
        {
            printf ("[");
            bst_inorder(&daun, mboh);
            printf("]\n");
        }
        else if (flag == 0)
        {
            printf ("Aceng mengambil: %d dan %d\n", temp, X-temp);
            bst_remove(&pohon, temp);
            bst_remove(&pohon, X-temp);
            bst_remove(&daun, temp);
            bst_remove(&daun, X-temp);
        }
    }
}