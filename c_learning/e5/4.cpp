#include <stdio.h>
int main(void)
{
    /*********Begin*********/
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    int high = n-1, mid, low = 0;
    int arrow = n;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == m && mid < arrow){
            arrow = mid;
        }else if(arr[mid] > m){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if(arrow != n){
        printf("%d", arrow+1);
    }else{
        printf("None");
    }
    /*********End**********/
    return 0;
}