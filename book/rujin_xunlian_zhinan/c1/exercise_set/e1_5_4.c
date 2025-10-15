#include <math.h>
#include <stdio.h>


int main() {
    double n;
    if (scanf("%lf", &n) != 1) {
        fprintf(stderr, "Input error: please provide a floating-point number.\n");
        return 1;
    }
    // n 为弧度；若输入为角度，请先转换：n = n * 3.141592653589793 / 180.0;
    printf("%.6f\n", sin(n));
    printf("%.6f\n", cos(n));

    return 0;
}
