#include <stdio.h>
#include <math.h>

int main(){
    char str[100];
    int i=0,num = 0;
    printf("请输入要转换的二进制字符串");
    scanf("%s",&str);
    while(str[i]!='\0'){
        num = num * 2 + (str[i] - '0');
        i++;
    }
    printf("%d", num);
}