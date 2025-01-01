#include <stdio.h>

int main(){
    int i ,j;
    for (int i = 101; i <= 200;i++){
        for (j = 2;j<i;j++){
            if(i%j==0){
            break;
            }
        }
        if(i == j){
            printf("%d\n", i);  
        }
    }
}
