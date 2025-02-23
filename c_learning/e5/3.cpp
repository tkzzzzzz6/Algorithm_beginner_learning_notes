#include <stdio.h>

#define Maxsize 1000
int main(void)
{
    /*********Begin*********/
    int n;
    scanf("%d", &n);
    int arr[Maxsize];
    for(int i = 0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int a,i;
    scanf("%d", &a);
    for(i = 0;i<n;i++){
        if(arr[i] == a){
            printf("%d", i+1);
            break;
        }
    }
    if(i == n){
        printf("-1");
    }
    /*********End**********/
    return 0;
}