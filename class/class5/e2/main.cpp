#include "stack.h"


int main()
{
    int m,j = 0,i=0;
    char n;
    char q[20];
    SqStack *s;
    printf("(1)初始化栈！\n");
    InitStack(s);
    printf("(2)判断栈是否为空：\n");
    if (StackEmpty(s))
        printf("栈为空\n");
    
    printf("(3)请输入要入栈的元素：以*结束\n");
    while (scanf("%c",&n) && n != '*'){
        Push(s,n);
    }
    printf("(4)显示栈内的元素：\n");
    DispStack(s);
    printf("(5)栈的长度为：%d\n", StackLength(s));
    printf("(6)请输入想要进行的出栈次数：\n");
    scanf("%d",&m);
    if (m > StackLength(s)){
        printf("(7)出栈次数超出栈的长度\n");
    }
    else{
        for (int j = 0; j < m; j++){
            Pop(s,n);
        }
        printf("(8)出栈操作以后：\n");
        DispStack(s);
        printf("(9)出栈后栈的长度为：%d\n", StackLength(s));
    }
    printf("(10)销毁栈！");
    DestroyStack(s);
    return 0;
}



