#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    float f;
    if(scanf("%f",&f)!=1){
        fprintf(stderr,"Input error: please provide three integers.\n");
        return 1;
    }
    printf("%.3f\n",(f-32)/1.8);

    return 0;
}
