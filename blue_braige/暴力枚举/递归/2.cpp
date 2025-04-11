#include <iostream>
#include <algorithm>

using namespace std;

int feibo(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return feibo(n - 1) + feibo(n - 2);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", feibo(n));
    return 0;
}