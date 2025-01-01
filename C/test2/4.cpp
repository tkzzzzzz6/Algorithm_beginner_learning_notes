#include <stdio.h>
#include <math.h>
int main(){
    int i,j,k,n;
    for (n = 100; n < 1000; n++)
    {
        i = n/100;
        j = n / 10 % 10;
        k = n % 10;
        if(n == pow(i,3)+pow(j,3)+pow(k,3)){
            printf("%d\n", n);
        }
    }
}