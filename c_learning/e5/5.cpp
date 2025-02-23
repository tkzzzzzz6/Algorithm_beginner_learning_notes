#include <stdio.h>

void delete_num(int a[],int n,int max){
    for(int i = max;i<n-1;i++){
        a[i] = a[i+1];
    }
} 

int main(void)
{
    /*********Begin*********/
    int i,a[10];
    for(i = 0;i<10;i++){
        scanf("%d", &a[i]);
    }
    int max = 0;
    for (i = 1; i < 10;i++){
        if(a[i] > a[max]){
            max = i;
        }
    }
    delete_num(a,10,max);
    for(i = 0;i<9;i++){
        printf("%d ", a[i]);
    }


        /*********End**********/
        return 0;
}