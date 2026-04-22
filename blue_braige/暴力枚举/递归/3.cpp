#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    int f[n];
    f[1] = 1;
    f[2] = 2;
    if(n == 1 || n == 2){
        printf("%d", n);
        return 0;
    }
    for(int i = 3; i <= n; i++){
        f[i] = f[i - 1] + f[i -2];
    }
    printf("%d",f[n]);

    return 0;
}