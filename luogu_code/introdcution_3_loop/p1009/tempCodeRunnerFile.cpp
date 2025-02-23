#include <bits/stdc++.h>

using namespace std;

unsigned long long calc_s(int n){
    unsigned long long s = 1;
    for (int i = 1; i <= n; i++){
        s *= i;
    }
    return s;
}

int main(){
    int n;
    unsigned long long sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        sum += calc_s(i);
    }
    printf("%llu", sum);
    return 0;
}