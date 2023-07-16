#include <bits/stdc++.h>
using namespace std;

struct BSTNode
{
    BSTNode *left, *right;
    int key;
};

struct BST
{
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

    void cetak()
    {
        __cetak(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(int value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, int value)
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

    BSTNode *__insert(BSTNode *root, int value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode *__findMinNode(BSTNode *node)
    {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode *__remove(BSTNode *root, int value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
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

            BSTNode *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root)
    {
        if (root)
        {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    // void __cetak(BSTNode *root)
    // {
    //     if (root)
    //     {
    //         queue <BSTNode*> q;
    //         q.push(root);
    //         int level = 0;

    //         while (!q.empty())
    //         {
    //             int size = q.size();
    //             int n = size;

    //             while (n--)
    //             {
    //                 BSTNode* temp = q.front();
    //                 q.pop();

    //                 if (n == size-1 || n == 0) cout << temp->key << " ";

    //                 if (temp->right != NULL) q.push(temp->right);
    //             }
    //             cout << endl;
    //         }
    //     }
    // }
    void __cetakLevel(BSTNode *node, int level, vector<int> &nilai)
    {
        if (node == NULL)
            return;

        if (level == 1)
        {
            // cout << node->key << " ";
            nilai.push_back(node->key);
        }
        else if (level > 1)
        {

            __cetakLevel(node->left, level - 1, nilai);
            __cetakLevel(node->right, level - 1, nilai);
        }
    }

    int __hitungTinggi(BSTNode *node)
    {
        if (node == NULL)
            return 0;

        int tinggiKiri = __hitungTinggi(node->left);
        int tinggiKanan = __hitungTinggi(node->right);

        return 1 + max(tinggiKiri, tinggiKanan);
    }

    void __cetak(BSTNode *root)
    {
        int tinggi = __hitungTinggi(root);
        vector<int> nilai;

        for (int level = 1; level <= tinggi; level++)
        {
            __cetakLevel(root, level, nilai);
            sort(nilai.begin(), nilai.end(), greater<int>());
            cout << nilai[0] << endl;
            // cout << endl;
            nilai.clear();
        }
    }
};

int main()
{
    BST pohon;
    pohon.init();

    int num;
    while (cin >> num)
    {
        pohon.insert(num);
    }

    pohon.cetak();
}