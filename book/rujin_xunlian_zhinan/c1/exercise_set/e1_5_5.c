#include <math.h>
#include <stdio.h>


int main() {
    int number;
    if(scanf("%d", &number)==1){
        int amount = number*95;
        if(amount >= 300)printf("%.2lf\n", (double)(amount*0.85));
        else printf("%.2lf\n", (double)amount);
    }

    return 0;
}
