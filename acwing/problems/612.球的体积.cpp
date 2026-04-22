/*
* @acwing app=acwing.cn id=614 lang=C++
*
* 612. 球的体积
*/

// @acwing code start
#include <stdio.h>
#include <iomanip>

int main(){
    int r;
    scanf("%d",&r);
    const double PI = 3.14159;
    printf("VOLUME = %.3f",4/3.0*PI*r*r*r);
    return 0;
}

// @acwing code end
