
#include "listack.h"

int main()
{
    int m,i=0;
    char n,e;
    LiStack *s;
    printf("(1)初始化栈！\n");
    InitStack(s);

    printf("(2)请输入要入栈的元素：\n");
    while (scanf("%c",&n) && n != '*'){
        Push(s,n);
    }



    printf("(3)判断栈是否为空\n");
    if (StackEmpty(s))
        printf("栈为空\n");
    else
        printf("栈非空\n");



    printf("(4)栈内的元素为：\n");
    DispStack(s);
    printf("(5)栈的长度为：%d\n", StackLength(s));
    printf("请输入想要进行的出栈次数：\n");
    scanf("%d",&m);
    if (m > StackLength(s)){
        printf("(6)超出实际栈的元素个数!\n");
    }
    else{
        for (int j = 0; j < m; j++){
            Pop(s,n);
        }
        printf("(6)出栈操作以后站内剩下的元素为：\n");
        DispStack(s);
        printf("(7)出栈后栈的长度为：%d\n", StackLength(s));
    }

    printf("(8)销毁栈！");
    DestroyStack(s);
    return 0;
}



