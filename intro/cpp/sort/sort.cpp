#define FILE_IO
#define bob_sort
#include <stdio.h>
#include <string.h>

int a[1005];

int main(){
    #ifdef FILE_IO
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // get input to arrays
    int n,size = 0;
    memset(a, 0, sizeof(a));
    while (scanf("%d", &n) != EOF)
    {
        a[size] = n;
        size++;
    }

    #ifdef bob_sort
    for (int i = 0; i < size;++i)
    {
        for (int j = size-1; j > i;--j){
            if(a[j]<a[j-1]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    #endif

    // output the sorted array
    for (int i = 0; i < size;++i)
        printf("%d ", a[i]);    
    printf("\n");
    

    return 0;
}
