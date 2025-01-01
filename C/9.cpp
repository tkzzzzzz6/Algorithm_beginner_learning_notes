#include <stdio.h>

int main(){
    int i,j;
    for(i =1;i<10;i++){
        for (j = 1; j < 10; j++)
        {
            if(i>j){
                printf("     ");
            }
            else
                printf("%d*%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }
}