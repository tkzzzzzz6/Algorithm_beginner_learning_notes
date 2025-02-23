#include <bits/stdc++.h>
using namespace std;

unsigned long long calc_factorial(int n) {
    unsigned long long s = 1;
    for (int i = 1; i <= n; i++) {
        s *= i;
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    unsigned long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += calc_factorial(i);
    }
    printf("%llu\n", sum);
    return 0;
}