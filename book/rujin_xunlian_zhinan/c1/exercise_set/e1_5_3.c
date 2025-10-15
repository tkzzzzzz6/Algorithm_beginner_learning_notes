#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d",&n)!=1) {
        return 1;
    }
    long long sum = n*(n-1)/2;
    printf("%lld\n",sum);
    return 0;
}
