#include <stdio.h>
int a = 10;
int main(void){
    {
        int a = 20;
        printf("内层的a%d\n",a);
    }
    printf("外层的a%d\n",a);
    return 0;
}