#include <stdio.h>

void swap(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(){
    int a[10] = {9,68,57,46,5,4,3,2,1,10};
    int i,j,k;
    for (i = 0; i < 10;i++){
        for (j = 0; j < 9; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
    for (k = 0;k<10;k++){
        printf("%d", a[k]);
    }
}