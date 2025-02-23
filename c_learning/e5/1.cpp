#include <stdio.h>
int main(void)
{
    /*********Begin*********/
    int m,j,k;
    int a[10];
    printf("Input m:");
    scanf("%d", &m);
    printf("Input array:\n");
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    j = a[0];
    for(int i = 1; i < m; i++){
        if(a[i] > j){
            j = a[i];
            k = i;
        }
    }
    printf("最大值=%d,下标=%d", j, k);

    /*********End**********/
    return 0;
}