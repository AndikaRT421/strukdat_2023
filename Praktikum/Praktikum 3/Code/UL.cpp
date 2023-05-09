#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
// #define MAX 52

int total_stage = 0;

int max(int a, int b) { return (a > b) ? a : b; }

typedef struct AVLNode
{
    int key;
    int height;
    long long strength;
    struct AVLNode *left, *right, *parent;
} AVLNode;

typedef struct avl_t
{
    unsigned int size;
    AVLNode *root;
} Avl;

AVLNode *createNode(int value, int str, AVLNode *parent)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->key = value;
    newNode->height = 1;
    newNode->strength = str;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

int getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

AVLNode *rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    newParrent->parent = pivotNode->parent;
    pivotNode->left = newParrent->right;
    if (newParrent->right)
        newParrent->right->parent = pivotNode;
    newParrent->right = pivotNode;
    pivotNode->parent = newParrent;

    pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
    newParrent->height = max(getHeight(newParrent->left), getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    newParrent->parent = pivotNode->parent;
    pivotNode->right = newParrent->left;
    if (newParrent->left)
        newParrent->left->parent = pivotNode;
    newParrent->left = pivotNode;
    pivotNode->parent = newParrent;

    pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right)) + 1;
    newParrent->height = max(getHeight(newParrent->left), getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *leftCaseRotate(AVLNode *node)
{
    return rightRotate(node);
}

AVLNode *rightCaseRotate(AVLNode *node)
{
    return leftRotate(node);
}

AVLNode *leftRightCaseRotate(AVLNode *node)
{
    AVLNode *temp = leftRotate(node->left);
    node->left = temp;
    temp->parent = node;
    return rightRotate(node);
}

AVLNode *rightLeftCaseRotate(AVLNode *node)
{
    AVLNode *temp = rightRotate(node->right);
    node->right = temp; //tes
    temp->parent = node;
    return leftRotate(node);
}

int getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode *insert(AVLNode *node, int value, int str, AVLNode *parent)
{
    if (node == NULL)
        return createNode(value, str, parent);
    if (value < node->key)
        node->left = insert(node->left, value, str, node);
    else if (value > node->key)
        node->right = insert(node->right, value, str, node);

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->key)
        return leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->key)
        return leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->key)
        return rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->key)
        return rightLeftCaseRotate(node);

    return node;
}

AVLNode *search(AVLNode *root, int value)
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

void avl_init(Avl *avl)
{
    avl->size = 0u;
    avl->root = NULL;
}

bool avl_find(Avl *avl, int value)
{
    AVLNode *temp = search(avl->root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void avl_insert(Avl *avl, int value, int str)
{
    if (!avl_find(avl, value))
    {
        avl->root = insert(avl->root, value, str, avl->root);
        avl->size++;
    }
}

// void cek_musuh(AVLNode *root, int indexx, int key[MAX][MAX], int strength[MAX][MAX], int sum[MAX], int kondisi_terbaru[MAX])
// {
//     if (root)
//     {
//         cek_musuh(root->left, indexx, key, strength, sum, kondisi_terbaru);
//         key[indexx][kondisi_terbaru[indexx]] = root->key;
//         strength[indexx][kondisi_terbaru[indexx]] = root->strength;
//         sum[indexx] += root->strength;
//         kondisi_terbaru[indexx]++;
//         cek_musuh(root->right, indexx + 1, key, strength, sum, kondisi_terbaru);
//     }
// }

// bool Lawan_Monster(AVLNode *root, int *stage, char planet[], int power)
// {
//     int key[MAX][MAX], strength[MAX][MAX], sum[MAX], kondisi_terbaru[MAX];
//     // vector <int> sum;
//     // vector <int> kondisi_terbaru;
//     memset(sum, 0, sizeof(sum));
//     memset(kondisi_terbaru, 0, sizeof(kondisi_terbaru));
//     cek_musuh(root, 0, key, strength, sum, kondisi_terbaru);

//     for (int i = 0; i < total_stage; i++)
//     {
//         if (i == total_stage - 1)
//         {
//             cout << "Final Stage:" << endl;
//             for (int j = 0; j < kondisi_terbaru[i]; j++)
//                 // cout << "Boss" << planet << "_" << key[i][j] << ": " << strength[i][j] << endl;
//                 printf("Boss %s_%d: %d\n", planet, key[i][j], strength[i][j]);
//         }
//         else
//         {
//             cout << "Stage " << i + 1 << ":" << endl;
//             for (int j = 0; j < kondisi_terbaru[i]; j++)
//             {
//                 char code = 'A' + j;
//                 // cout <<
//                 printf("Monster %c%d_%d_%d: %d\n", code, key[i][j], i + 1, j + 1, strength[i][j]);
//             }
//             cout << "=>" << endl;
//         }
//         if ((i + 1) % 2 != 0)
//             sum[i] *= 0.9;
//         else
//             sum[i] *= 0.8;
//         power -= sum[i];
//         if (power > 0)
//             (*stage)++;
//     }
//     if (power > 0)
//         return true;
//     else
//         return false;
// }

void banyak_stage(AVLNode *root)
{
    if (root)
    {
        total_stage++;
        banyak_stage(root->right);
    }
}

void jenis_monster(AVLNode *root, map<int, vector<AVLNode *>> &kondisi, int mid)
{
    if (root)
    {
        jenis_monster(root->left, kondisi, mid);
        kondisi[mid].push_back(root);
        jenis_monster(root->right, kondisi, mid + 1);
    }
}

// MAIN FUNCTION
int main()
{
    Avl Avl_coy;
    avl_init(&Avl_coy);
    int n;
    double power;
    char planet[1000];
    cin >> n >> power;
    scanf("%s", planet);
    while (n--)
    {
        int key_node, dmg;
        cin >> key_node >> dmg;
        avl_insert(&Avl_coy, key_node, dmg);
    }
    cout << "Ultraman lapet(Power: " << power << ")" << endl;
    cout << "Planet: " << planet << endl;
    // cout << "-----------------------" << endl;
    puts("-----------------------");
    banyak_stage(Avl_coy.root);
    // int stage_awal = 1;
    map<int, vector<AVLNode *>> kondisi;
    jenis_monster(Avl_coy.root, kondisi, 0);

    int dikalahkan = -1;
    for (int i = 0; i < total_stage; i++)
    {
        int stage_now = i + 1;
        long long serangan = 0;
        if (stage_now == total_stage)
        {
            // cout << "Final Stage:" << endl;
            puts("Final Stage:");
            for (int j = 0; j < kondisi[i].size(); j++)
            {
                serangan += kondisi[i][j]->strength;
                printf("Boss %s_%d: %d\n", planet, kondisi[i][j]->key, kondisi[i][j]->strength);
            }
        }
        else
        {
            cout << "Stage " << stage_now << ":" << endl;
            for (int j = 0; j < kondisi[i].size(); j++)
            {
                serangan += kondisi[i][j]->strength;
                printf("Monster %c%d_%d_%d: %d\n", j + 'A', kondisi[i][j]->key, stage_now, j + 1, kondisi[i][j]->strength);
            }
        }

        if (stage_now % 2 == 0)
            serangan *= 0.8;
        else
            serangan *= 0.9;
        power -= serangan;

        if (power < 0 && dikalahkan == -1)
            dikalahkan = stage_now;

        if ((stage_now) != total_stage)
            puts("=>");
    }
    // cout << "\nResult:" << endl;
    puts("\nResult:");
    if (power > 0)
        printf("Ultraman Lapet lolos dari Planet %s", planet);
    else if (dikalahkan != total_stage)
        printf("Ultraman Lapet terperangkap di Planet %s pada Stage %d", planet, dikalahkan);
    else
        printf("Ultraman Lapet terperangkap di Planet %s pada Final Stage", planet);
}
