#include <iostream>
#include <stdio.h>
#include "btree.h"

//using namespace std;
int Nodes(BTNode *b)
{	//请在这里补充代码实现二叉树节点计数功能
	if(b == NULL)
		return 0;
	else
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;

}

int main()
{
	//请在这里补充代码实现调用创建二叉树的函数，并以括号表示法显示该树，然后调用 Nodes(BTNode *b)函数实现二叉树节点计数功能，并显示出节点总数。
    BTNode *b;
	printf("请以括号表示法输入要建立的二叉树\n");
	char str[MaxSize];
	scanf("%s",str);
	CreateBTNode(b,str);
	printf("这棵二叉树的括号表示法输出为：\n");
	DispBTNode(b);
	printf("\n");
	printf("节点个数:%d\n",Nodes(b));

	return 1;
}