#include <stdio.h>

int main(){
    int a[] = {1, 3, 5, 7},n=0;
    for(int i=0;i<4;i++){
        for (int j = 0;j<4;j++){
            for(int k = 0;k<4;k++){
                if(i!=j&&i!=k&&j!=k){
                    n++;
                    printf("%d ", a[i] * 100 + a[j] * 10 + a[k]);
                }
            }
        }
    }
    printf("共有%d个数", n);
}