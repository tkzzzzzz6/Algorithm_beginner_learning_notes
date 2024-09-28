#include <stdio.h>

int a,b,i = 0;

int main(){
    while (i<5)
    {
        printf("a++ = %d,++b = %d\n",a++,++b);
        i += 1;
    };
        return 0;
}