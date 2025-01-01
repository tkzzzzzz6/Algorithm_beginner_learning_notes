#include <stdio.h>

int main(){
    int i,k=0;
    for (i = 99; i < 1000;i++){
        if(i%3 == 0 && i%7 == 0 && i/10%10!=2){
            printf("%d ", i);
            k++;
            if(k%3 == 0){
                printf("\n");
            }
        }
    }
}