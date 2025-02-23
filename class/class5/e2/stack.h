
#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;
                   
} SqStack;                  //顺序栈类型定义

void InitStack(SqStack *&s);    //初始化栈
void DestroyStack(SqStack *&s);  //销毁栈
bool StackEmpty(SqStack *s);     //栈是否为空
int StackLength(SqStack *s);  //返回栈中元素个数——栈长度
bool Push(SqStack *&s,ElemType e); //入栈
bool Pop(SqStack *&s,ElemType &e); //出栈
bool GetTop(SqStack *s,ElemType &e); //取栈顶数据元素
void DispStack(SqStack *s);  //输出栈


