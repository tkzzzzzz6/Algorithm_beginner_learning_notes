#include "stack.h"

int main()
{
    SqStack *s;
    printf("(1)初始化栈！\n");
    InitStack(s);
    char st[100];
    printf("(2)请输入表达式：\n");
    
    if (fgets(st, 100, stdin) != NULL) {
        // 移除可能的换行符
        int i;
        for (i = 0; st[i] != '\0' && st[i] != '\n'; i++);
        if (st[i] == '\n') st[i] = '\0';
        
        for (i = 0; st[i] != '\0'; i++) {
            Push(s, st[i]);
        }
        
        if (MatchBrackets(st, s))
            printf("括号匹配！\n");
        else
            printf("括号不匹配！\n");
    } else {
        printf("读取输入失败\n");
    }
    
    return 0;
}









