#include <stdio.h>

int main(){
    int i,j=0;
    for (i = 100;i<1000;i++){
        if(i%3==0&&i%5==0&&i/10%10!=0){
            printf("%d ", i);
            j++;
            if(j%5 == 0){
                printf("\n");
            }
        }
    }
}