#include <iostream>
#include <vector>
using namespace std;

int urutan = 0;

struct BSTNode
{
    BSTNode *left;
    BSTNode *right;
    int key;
};

struct BST
{
    BSTNode *_root;
    unsigned int _size;

    void init()
    {
        _root = nullptr;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == nullptr;
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

    bool find2(int value, vector<char> &rute)
    {
        BSTNode *temp = __search2(_root, value, rute);
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

    void traverseInorder(int angka)
    {
        int kedalaman = 0;
        int hasil = -1;
        inorder(_root, kedalaman, angka, hasil);
        cout << hasil << endl;
    }

    int level(int angka)
    {
        return getLevelUtil(_root, angka, 1);
    }

private:
    BSTNode *__createNode(int value)
    {
        BSTNode *newNode = new BSTNode();
        newNode->key = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, int value)
    {
        while (root != nullptr)
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

    BSTNode *__search2(BSTNode *root, int value, vector<char> &rute)
    {
        while (root != nullptr)
        {
            if (value < root->key)
            {
                rute.push_back('L');
                root = root->left;
            }
            else if (value > root->key)
            {
                rute.push_back('R');
                root = root->right;
            }
            else
            {
                rute.push_back('S');
                return root;
            }
        }
        return root;
    }

    BSTNode *__insert(BSTNode *root, int value)
    {
        if (root == nullptr)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    void __inorder(BSTNode *root, int angka)
    {
        if (root)
        {
            __inorder(root->left, angka);
            urutan++;
            if (root->key > angka)
            {
                cout << -1 << endl;
                return;
            }
            if (root->key == angka)
            {
                cout << urutan << endl;
            }
            __inorder(root->right, angka);
        }
    }

    void inorder(BSTNode *root, int &kedalaman, int angka, int &hasil)
    {
        if (root == NULL)
            return;

        inorder(root->left, kedalaman, angka, hasil);
        kedalaman++;
        if (kedalaman == angka)
        {
            hasil = root->key;
            return;
        }
        inorder(root->right, kedalaman, angka, hasil);
    }

    int getLevelUtil(BSTNode *root, int angka, int level)
    {
        if (root == nullptr)
            return 0;
        if (root->key == angka)
            return level;

        int downlevel = getLevelUtil(root->left, angka, level + 1);

        if (downlevel != 0)
            return downlevel;

        downlevel = getLevelUtil(root->right, angka, level + 1);
        return downlevel;
    }
};

int main()
{
    BST bst;
    bst.init();

    string perintah;
    cin >> perintah;
    while (perintah != "STOP")
    {
        int angka;
        cin >> angka;
        if (perintah == "IN")
        {
            bst.insert(angka);
        }
        else if (perintah == "FD")
        {
            int kedalaman = bst.level(angka);
            if (kedalaman)
                printf("on level %d\n", kedalaman);
            else
                printf("no %d\n", angka);
        }
        else if (perintah == "RK")
        {
            bst.traverseInorder(angka);
        }
        else if (perintah == "PH")
        {
            vector<char> rute;
            if (bst.find2(angka, rute))
            {
                for (char i : rute)
                {
                    printf("%c", i);
                }
                printf("\n");
            }
            else
                printf("no %d\n", angka);
        }
        cin >> perintah;
    }
    cout << "done" << endl;
    return 0;
}
