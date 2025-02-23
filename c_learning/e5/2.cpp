#include <stdio.h>
int main(void)
{
    /*********Begin*********/
    int a[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }
    // 采用选择排序
    for (int i = 0; i < 10;i++){
        int Max = i;
        for (int j = i + 1;j<10;j++){
            if(a[j] > a[Max]){
                Max = j;
            }
        }
        int temp = a[i];
        a[i] = a[Max];
        a[Max] = temp;
    }
    for (int i = 0;i<10;i++){
        printf("%d ", a[i]);
    }
        /*********End**********/
        return 0;
}