#include <stdio.h>
#include <malloc.h>
#include "btree.h"

void CreateBTNode(BTNode *&b, char *str)
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1;
    int k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = -1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL)
                b = p;
            else
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

BTNode *FindNode(BTNode *b, ElemType x)
// 尝试采用中序遍历的方法查找值为x的节点
{
    if(b == NULL)
        return NULL;

    BTNode *p = FindNode(b->lchild, x);
    if (p != NULL)
        return p;
    if (b->data == x)
        return b;
    return FindNode(b->rchild,x);
}

BTNode *LchildNode(BTNode *p)   //返回*p节点的左孩子节点指针
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)   //返回*p节点的右孩子节点指针
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b)
{
    int lchilddep, rchilddep;
    if(b == NULL)
        return 0;
    else{
        lchilddep = BTNodeDepth(b->lchild);
        rchilddep = BTNodeDepth(b->rchild);
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

void DispBTNode(BTNode *b)
{
    if(b != NULL){
        printf("%c",b->data);
        if(b->lchild != NULL || b->rchild != NULL){
            printf("(");
            DispBTNode(b->lchild);
            if(b->rchild != NULL)
                printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}

void DestroyBTNode(BTNode *&b)   //销毁二叉树
{   
    if(b != NULL){
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}

