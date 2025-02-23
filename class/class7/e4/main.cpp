#include <iostream>
#include <stdio.h>
#include "btree.h"

// using namespace std;

void PreOrder(BTNode *b) // 先序遍历的递归算法,采用非递归实现
{
	BTNode *p;
	BTNode *St[MaxSize];
	int top = -1;
	if(b != NULL){
		p = b;
		while(p != NULL || top != -1){
			while(p != NULL){
				printf("%c ",p->data);
				St[++top] = p;
				p = p->lchild;
			}
			if(top != -1){
				p = St[top--];
				p = p->rchild;
			}
		}
	}
}

int main()
{
	BTNode *b;
	char str[MaxSize];
	printf("请以括号表示法输入要建立的二叉树\n");
	scanf("%s", str);
	CreateBTNode(b, str);
	printf("先序遍历\n");
	PreOrder(b);
	return 1;
}
