#include <iostream>
#include <stdio.h>
#include "btree.h"

//using namespace std;


void PreOrder(BTNode *b)        //先序遍历的递归算法
{
  if(b != NULL){
    printf("%c ",b->data);
    PreOrder(b->lchild);
    PreOrder(b->rchild);
  }
}

void InOrder(BTNode *b)         //中序遍历的递归算法
{
    if(b != NULL){
        InOrder(b->lchild);
        printf("%c ",b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode *b)       //后序遍历的递归算法
{
   if(b != NULL){
    PostOrder(b->lchild);
    PostOrder(b->rchild);
    printf("%c ",b->data);
   }
   
}

int main()
{
	BTNode *b;
    char str[MaxSize];
    printf("请以括号表示法输入要建立的二叉树\n");
    scanf("%s",str);
    CreateBTNode(b,str);
    printf("先序遍历序列:\n");
    PreOrder(b);
    printf("\n");
    printf("中序遍历序列:\n");
    InOrder(b);
    printf("\n");
    printf("后序遍历序列:\n");
    PostOrder(b);
    return 1;
}
