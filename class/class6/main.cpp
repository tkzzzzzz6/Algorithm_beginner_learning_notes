 #include "btree.h"
 #include <stdio.h>

 int main(){
    char str[50];
    BTNode *b;
    printf("1.请以括号表示法输入要建立的二叉树\n");
    scanf("%s",str);
    CreateBTNode(b,str);
    printf("2.建立的二叉树如下：\n");
    DispBTNode(b);
    printf("\n");

    printf("3.请输入要查找的节点：\n");
    char x;
    getchar();
    scanf("%c", &x);
    BTNode *p = FindNode(b,x);
    if(p != NULL){
        printf("查找到%c的节点,该节点的左右孩子分别为%c %c\n",x, LchildNode(p)->data, RchildNode(p)->data);
    }

    int depth = BTNodeDepth(b);
    printf("4.该二叉树深度为%d\n", depth);

    printf("5.操作结束，释放该二叉树\n");
    DestroyBTNode(b);
    return 0;
 }