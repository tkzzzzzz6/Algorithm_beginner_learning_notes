// 采用散列表的方法
// 取手机号码后5为作为散列函数
// 采用分离链表法
#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    int data;
    int count;
    struct Node *next;
} Node;

typedef struct{
    Node *head[MaxSize];
    int size;
} HashTable;

void CreateTable(int N){
    int TableSize;
    HashTable *H;
    H = (HashTable)malloc(sizeof(HashTable));
    TableSize = NextPrime(2*N);
    H->size = N;
    for (int i = 0; i < N;i++){
        H->head[i] = NULL;
    }
};

void Insert(HashTable &H,ElementType Key){
    int index = Key % N;
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = Key;
};
void ScanAndOutput(HashTable H);
void DestroyTable(HashTable &H);





int main()
{   
    int N,i;
    ElementType Key;
    HashTable H;
    scanf("%d", &N);
    H = CreateTable(N*2);
    for (i = 0;i<N;i++){
        scanf("%d",&Key);Insert(H,Key);
        scanf("%d",&Key);Insert(H,Key);
    }
    ScanAndOutput(H);
    DestroyTable(H);
    return 0;
}