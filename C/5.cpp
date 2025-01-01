#include <stdio.h>
#include <math.h>

int main(){
    int num_10,num_2[100];
    scanf("%d", &num_10);
    int i;
    for (i = 0;num_10>0;i++){
        num_2[i] = num_10%2;
        num_10 /= 2;
    }
    int j = i;
    for (i = j - 1; i >= 0;i--)
        printf("%d", num_2[i]);
}