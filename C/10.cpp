#include <stdio.h>

unsigned long long jiechen(int n){
    if(n == 1 || n == 0)return 1;
    return n * jiechen(n - 1);
}

int main(){
    unsigned long long sum;
    int i;
    for (i = 1; i <= 50;i++)
        sum += jiechen(i);
    printf("%lu", sum);
}