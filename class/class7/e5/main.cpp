#include <iostream>
#include <stdio.h>
#include "btree.h"

using namespace std;

void LevelOrder(BTNode *b){
    BTNode *p;
    BTNode *qu[MaxSize];
    int front = 0,rear = 0;
    qu[rear] = b;
    rear = (rear + 1) % MaxSize;
    while(front != rear){
        p = qu[front];
        front = (front + 1) % MaxSize;
        printf("%c ",p->data);
        if(p->lchild != NULL){
            qu[rear] = p->lchild;
            rear = (rear + 1) % MaxSize;
        }
        if(p->rchild != NULL){
            qu[rear] = p->rchild;
            rear = (rear + 1) % MaxSize;
        }
    }
}

int main()
{ // 创建一棵二叉树，并且调用层次遍历非递归算法，进行遍历，并输出遍历结果
	printf("请以括号表示法输入要建立的二叉树\n");
    BTNode *b;
    char str[MaxSize];
    scanf("%s",str);
    CreateBTNode(b,str);
    printf("层次遍历的结果为：\n");
    LevelOrder(b);
    DestroyBTNode(b);
    return 1;
}