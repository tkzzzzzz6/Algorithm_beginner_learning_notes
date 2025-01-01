#include <stdio.h>

int main(){
    int a[] = {0, 2, 3, 4};
    int i, j,k,sum = 0;
    for(i=0;i<4;i++){
        for (j = 0;j<4;j++){
            for (k = 0; k< 4;k++){
                if(i!=j&&i!=k&&j!=k&&a[i]!=0){
                    sum = a[i] * 100 + a[j] * 10 + a[k];
                    printf("%d\n", sum);
                }
            }
        }
    }
}