#include <iostream>
using namespace std;
bool cek = true;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    Node *insertNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
        {
            return new Node(value);
        }

        if (value < currentNode->data)
        {
            currentNode->left = insertNode(currentNode->left, value);
        }
        else if (value > currentNode->data)
        {
            currentNode->right = insertNode(currentNode->right, value);
        }

        return currentNode;
    }

    Node *findMinNode(Node *currentNode)
    {
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode;
    }

    Node *deleteNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
        {
            return nullptr;
        }

        if (value < currentNode->data)
        {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->data)
        {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else
        {
            if (currentNode->left == nullptr)
            {
                Node *temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr)
            {
                Node *temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            Node *minRightNode = findMinNode(currentNode->right);
            currentNode->data = minRightNode->data;
            currentNode->right = deleteNode(currentNode->right, minRightNode->data);
        }

        return currentNode;
    }

    void inorderTraversal(Node *currentNode)
    {
        if (currentNode != nullptr)
        {
            inorderTraversal(currentNode->left);

            if ((currentNode->left == nullptr && currentNode->right != nullptr) ||
                (currentNode->left != nullptr && currentNode->right == nullptr))
            {
                cek = false;
                cout << currentNode->data << " ";
            }

            inorderTraversal(currentNode->right);
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void remove(int value)
    {
        root = deleteNode(root, value);
    }

    void ans()
    {
        inorderTraversal(root);
    }
};

int main()
{
    BST bst;

    int tes;
    cin >> tes;
    while (tes--)
    {
        int angka;
        cin >> angka;
        if (angka == 15)
        {
            int num;
            cin >> num;
            bst.insert(num);
        }
        else if (angka == 04)
        {
            int num;
            cin >> num;
            bst.remove(num);
        }
        else if (angka == 89)
        {
            bst.ans();
            cout << endl;
            if (cek)
            {
                cout << "Use whatever means you must to control our population. Just do it." << endl;
                cek = true;
            }
        }
    }
}