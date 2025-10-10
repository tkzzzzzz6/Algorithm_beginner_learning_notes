#include <stdio.h>
#define MAXN 105

int a[MAXN], n = 0;


int main(){
    int x = 0;
    while(scanf("%d", &x) == 1){
        a[n++] = x;
    }
    for(int i = n-1;i>=0;i--){
        printf("%d\n",a[i]);
    }
    return 0;
}
