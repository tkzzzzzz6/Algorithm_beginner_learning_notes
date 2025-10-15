#include <stdio.h>
#include <stdlib.h>

//这是一段汉诺塔的递归代码
void print(char x,char y)
{
    printf("%c-->%c\n",x,y);
}

void move(int n,char start,char temp,char end){
    if(n == 1){
        print(start,end);
    }else{
        move(n-1,start,end,temp); 
        print(start,end);
        move(n-1,temp,start,end);
    }
}

int main(){
    int n;
    printf("请输入盘子的个数：");
    scanf("%d",&n);
    move(n,'A','B','C');
    return 0;
}