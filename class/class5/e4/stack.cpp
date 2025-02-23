#include "stack.h"

void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    if (s == NULL){
        printf("内存分配失败！\n");
        exit(0);
    }
    s->top = -1;
}
void DestroyStack(SqStack *&s)
{
    free(s);
}
int StackLength(SqStack *s)  //返回栈中元素个数——栈长度
{
    return(s->top+1);
}
bool StackEmpty(SqStack *s)
{
    return(s->top==-1);
}
bool Push(SqStack *&s,ElemType e)
{
    if(s->top==MaxSize - 1)
    {
        return false;
    }

    s->top++;
    s->data[s->top] = e;
    return true;

}
bool Pop(SqStack *&s,ElemType &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s,ElemType &e)
{
    if (s->top==-1)         //栈为空的情况，即栈下溢出
        return false;
    e=s->data[s->top];
    return true;
}

void DispStack(SqStack *s)  //输出栈
{
    int i;
    for (i=s->top; i>=0; i--)
        printf("%c ",s->data[i]);
    printf("\n");
}




bool MatchBrackets(ElemType exp[], SqStack *&s)
{
    char e;
    
    // 确保开始时栈为空
    while (!StackEmpty(s)) {
        Pop(s, e);
    }

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            Push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (StackEmpty(s)) {
                return false;  // 右括号多于左括号
            }
            Pop(s, e);
            if ((exp[i] == ')' && e != '(') ||
                (exp[i] == ']' && e != '[') ||
                (exp[i] == '}' && e != '{')) {
                return false;  // 括号不匹配
            }
        }
    }

    // 检查是否所有左括号都被匹配
    if (StackEmpty(s)) {
        return true;  // 匹配成功
    } else {
        return false;  // 左括号多于右括号
    }
}
