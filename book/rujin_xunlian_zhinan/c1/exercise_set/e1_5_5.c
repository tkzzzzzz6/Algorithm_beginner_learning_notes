#include <math.h>
#include <stdio.h>


int main() {
    double n;
    if(scanf("%lf",&n)!=1)return 1;
    printf("%f\n",sin(n));
    printf("%f\n",cos(n));

    return 0;
}
