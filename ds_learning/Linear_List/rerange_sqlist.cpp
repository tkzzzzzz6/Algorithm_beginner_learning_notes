#include <stdio.h>

void Insert1(SqList *&L){
    int x;
    scanf("%d",&x);
    if(x<1||x>L->length)
        return;
    for (int i = 0; i < L->length;i++){
        if(L->data[i] == x){
            for (int j = L->length; j >i-1;j--){
                L->data[j] = L->data[j - 1];
            }
            L->length++;
            L->data[i] = x;
        }
    }
}

void Insert2(SqList *&L){
    int i = 0, j;
    while(i<L->length && L->data[i] != x)
        i++;
    for (j = L->length; j >= i;j--){
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = x;
    L->length++;
}

int LocateElem(SqList *L,ElemType e){
    int i = 0;
    while(i<L->length && L->data[i]!=e)
        i++;
    if (i>=L->length)return 0;
    else
        return i + 1;
}

void delnode1(SqList *&L,ElemType e){
    int i;
    ElemType e;
    while(LocateElem(L,e)){
        ListDelete(L, i, e);
    }
}

void delnode2(SqList *&L,ElemType e){
    int k = 0, i;//k记录不等于e的元素个数
    for(L->data[i] != e){
        L->data[k] = L->data[i];
        k++;
    }
    L->length = k;
}

void MergeList(SqList *LA,SqList *LB,SqList *&LC){
    int i = 0, j = 0, k = 0;
    while(i<=A->length&&j<=B->length){
        if(LA->data[i]<=LB->data[j])
            LC->data[k++];
        else
            LC->data[k++] = LB->data[j++];
    }
    while(i<=LA->length)
        LC->data[k++] = LA->data[i++];
    while(j<=LB.length)
        LC->data[k++] = LB->data[j++];
    LC->length = k - 1;
}
