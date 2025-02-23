#include<stdio.h>
int main()
{ 
    /************Begin************/
    for (int i = 1; i < 10;i++){
        int k = i - 1;
        while (k > 0)
        {
            printf("       ");
            k--;
        }
        for (int j = i; j < 10;j++){

            printf("%d*%d=%2d ",i,j,i*j);
        }
        printf("\n");
    }

    /***************End***********/
}