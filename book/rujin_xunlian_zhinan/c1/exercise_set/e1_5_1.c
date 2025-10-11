#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a,b,c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        fprintf(stderr, "Input error: please provide three integers.\n");
        return 1;
    }
    printf("%.3f\n",(a+b+c)/3.0);

    return 0;
}
