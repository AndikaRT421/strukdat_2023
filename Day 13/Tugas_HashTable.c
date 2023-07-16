#include <stdio.h>
#include <stdlib.h>

#define size 7
int arr[size];

typedef struct snode_t
{
    int data, key;
    struct snode_t *next;
} SListNode;

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

SinglyList *mylist;

void list_init()
{
    mylist = (SinglyList *)malloc(sizeof(SinglyList));
    mylist->_head = NULL;
    mylist->_size = 0;
}

void list_insert(int value, int key)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        mylist->_size++;
        newNode->data = value;
        newNode->key = key;
        newNode->next = NULL;

        if (mylist->_head == NULL)
        {
            mylist->_head = newNode;
        }
        else
        {
            SListNode *bantu = mylist->_head;
            while (bantu->next != NULL)
            {
                bantu = bantu->next;
            }
            bantu->next = newNode;
        }
    }
}

void init()
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d masuk pada arr[%d]\n", value, key);
    }
    else
    {
        list_insert(value, key);
        printf("Terjadi Collision : arr[%d] element %d sudah ada \n", key, arr[key]);
        // printf("Insert di batalkan  %d\n", value);
    }
}

void del(int value)
{
    int key = value % size;
    if (arr[key] == value)
    {
        int flag = 0;
        SListNode *bantu = mylist->_head;
        while (bantu != NULL)
        {
            if (bantu->key == key)
            {
                arr[key] = bantu->data;
                flag = 1;
            }
            bantu = bantu->next;
        }
        if (flag == 0)
            arr[key] = -1;
    }
    else
        printf("%d not present in the hash table\n", value);
}

void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void print()
{
    int i;
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
    list_init();
    init();
    insert(10); // key = 10 % 7 ==> 3
    insert(4);  // key = 4 % 7  ==> 4
    insert(2);  // key = 2 % 7  ==> 2
    insert(3);  // key = 3 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();
    printf("\n");
    printf("Yang mengalami Collision:\n");
    SListNode *bantu = mylist->_head;
    while (bantu != NULL)
    {
        printf("Arr [%d] dengan value = %d\n", bantu->key, bantu->data);
        bantu = bantu->next;
    }

    printf("Deleting value 10..\n");
    del(10);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Deleting value 5..\n");
    del(5);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Searching value 4..\n");
    search(4);
    printf("Searching value 10..\n");
    search(10);

    return 0;
}