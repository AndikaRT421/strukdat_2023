#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    BSTNode* left, * right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode* _root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode* temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    bool Rahasia(int K) {
        return cek_jumlah(_root, K);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode* newNode = new BSTNode();
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode* __search(BSTNode* root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode* root, int value) {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    bool cek_jumlah(BSTNode* root, int K) {
        if (root) {
            if (root->left && root->right) {
                int A = root->key;
                int B = root->left->key;
                int C = root->right->key;
                if (A + B + C == K)
                    return true;
            }

            if (root->left == NULL) {
                if (root->right && root->right->right) {
                    int A = root->key;
                    int B = root->right->key;
                    int C = root->right->right->key;
                    if (A + B + C == K)
                        return true;
                }
            }

            if (root->right == NULL) {
                if (root->left && root->left->left) {
                    int A = root->key;
                    int B = root->left->key;
                    int C = root->left->left->key;
                    if (A + B + C == K)
                        return true;
                }
            }
            return cek_jumlah(root->left, K) || cek_jumlah(root->right, K);
        }
        return false;
    }
};

int main() {
    BST pohon;
    pohon.init();
    int test;
    cin >> test;
    while (test--) {
        int angka;
        cin >> angka;
        pohon.insert(angka);
    }
    int K;
    cin >> K;

    if (pohon.Rahasia(K)) {
        cout << K << " Selamat! Kalian menemukan harta karunnya\n"
             << endl;
    }
    else {
        cout << K << " Tidak ada kombinasi yang tepat! Bikin ulang.\n"
             << endl;
    }
}
