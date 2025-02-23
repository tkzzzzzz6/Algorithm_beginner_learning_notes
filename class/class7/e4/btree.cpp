#include <stdio.h>
#include <malloc.h>
#include "btree.h"

void CreateBTNode(BTNode *&b,char *str)     //由str串创建二叉链
{
    BTNode *St[MaxSize],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;             //建立的二叉树初始时为空
    ch=str[j];
    while (ch!='\0')    //str未扫描完时循环
    {
        switch(ch)
        {
        case '(':
            top++;
            St[top]=p;
            k=1;
            break;      //为左节点
        case ')':
            top--;
            break;
        case ',':
            k=2;
            break;                          //为右节点
        default:
            p=(BTNode *)malloc(sizeof(BTNode));
            p->data=ch;
            p->lchild=p->rchild=NULL;
            if (b==NULL)                    //p指向二叉树的根节点
                b=p;
            else                            //已建立二叉树根节点
            {
                switch(k)
                {
                case 1:
                    St[top]->lchild=p;
                    break;
                case 2:
                    St[top]->rchild=p;
                    break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}
BTNode *FindNode(BTNode *b,ElemType x)  //返回data域为x的节点指针
{
    BTNode *p;
    if (b==NULL)
        return NULL;
    else if (b->data==x)
        return b;
    else
    {
        p=FindNode(b->lchild,x);
        if (p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}
BTNode *LchildNode(BTNode *p)   //返回*p节点的左孩子节点指针
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)   //返回*p节点的右孩子节点指针
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b)  //求二叉树b的深度
{
    int lchilddep,rchilddep;
    if (b==NULL)
        return(0);                          //空树的高度为0
    else
    {
        lchilddep=BTNodeDepth(b->lchild);   //求左子树的高度为lchilddep
        rchilddep=BTNodeDepth(b->rchild);   //求右子树的高度为rchilddep
        return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
    }
}
void DispBTNode(BTNode *b)  //以括号表示法输出二叉树
{
    if (b!=NULL)
    {
        printf("%c",b->data);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            if (b->rchild!=NULL) printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}
void DestroyBTNode(BTNode *&b)   //销毁二叉树
{
    if (b!=NULL)
    {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}
