#include <stdio.h>

int main(){
    char str[100];
    scanf("%s", str);
    int i = 0,cnt = 0;
    while(str[i]!='\0'){
        if(str[i]>='A'&&str[i]<='Z'){
            printf("%c", str[i]);
            cnt++;
            i++;
        }
    }
    printf("the number of cnt is");
    printf("%d", cnt);
}