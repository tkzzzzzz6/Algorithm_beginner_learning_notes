#include <stdio.h>

void PrintN(int N){
    if (N){
        PrintN(N-1);
        printf("%d\n", N);
    }
    return;
}

void PrintN2(int N){
    int i;
    for (i = 1; i <= N ; i++){
        printf("%d\n", i);
    }
    return;
}

int main(){
    int N = 1000;
    printf("循环实现\n");
    PrintN(N);
    printf("递归实现\n");
    PrintN2(N);
    return 0;
}