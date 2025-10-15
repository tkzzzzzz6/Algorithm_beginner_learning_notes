#include <bits/stdc++.h>

using namespace std;

#define MaxWordLength 100

typedef struct{
    char word[MaxWordLength];
    int count;
}ElemType;

typedef struct{
    ElemType *elem;
    int size;
}HashTable;

void InitHashTable(HashTable &H){
    H.size = 0;
}

void FatalError(char *error){
    fprintf(stderr,"%s",error);
    exit(1);
}


int main(){
    int TableSize = 13;
    int wordcout = 0,length;
    HashTable H;
    ElemType word;
    FILE *fp;
    char document[MaxWordLength] = "Harry Potter.txt";
    InitHashTable(H);
    if(fp = fopen(document,"r") == NULL){
        FatalError("文件无法打开\n");
    }
}