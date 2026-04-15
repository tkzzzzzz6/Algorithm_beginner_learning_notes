#include <stdio.h>

#define MaxSize 100 
typedef struct{
    // 保存数据的数组
    int data[MaxSize];//MaxSize就是数组元素的个数,最后一个下标是元素个数-1
    //栈顶指针
    int top;
} Stack;

//初始化栈
void InitStack(Stack* stack){
    //但栈为空时,栈顶指针为-1
    stack->top = -1;
}

//判断栈顶是否为空
int isEmpty(Stack* stack){
    return stack->top == -1;
}

//弹出栈元素
int pop(Stack* stack){
    //判断栈是否为空
    if(isEmpty(stack)){
        printf("栈为空\n");
        return 0;
    }
    return stack->data[stack->top--];
}

//栈压入元素
int isFull(Stack* stack){
    return stack->top == MaxSize - 1;
}

void push(Stack* stack, int val){
    if(isFull(stack)){
        printf("栈已满\n");
        return; 
    }
    stack->data[++stack->top] = val;
}

//获取栈顶元素值
int top(Stack* stack){
    //如果栈空,无法获取
    if(isEmpty(stack)){
        printf("栈为空\n");
        return 0;
    }
    return stack->data[stack->top];
}

int main(){
    //定义一个栈
    Stack s1;
    InitStack(&s1);

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    push(&s1, 40);
    push(&s1, 50);
    push(&s1, 60);

    int topval;
    //栈底到栈顶:10 20 30 40 50 60
    //出栈顺序:60 50 40 30 20 10
    while(!isEmpty(&s1)){
        topval = top(&s1);
        printf("%d\n", topval);
        pop(&s1);
    }
    pop(&s1);//栈空无法弹出

    return 0;
}