#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    int T;
    cin >> T;
    int a[T];
    
    for(int i = 0;i < T;i++){
        int x, y, N;
        cin >> x >> y;
        N = (int)(x * y) / pow(gcd(x, y), 2);
        a[i] = N;
    }
    for(int i = 0;i < T;i++){
        printf("1 %d\n",a[i]);
    }
    return 0;
}
