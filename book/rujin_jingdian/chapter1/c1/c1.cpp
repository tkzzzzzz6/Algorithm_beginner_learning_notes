#include <cstdio>
#include <cmath>

float r;
int h;
const double PI = 3.1415926;

void showArea(float r,int h){
    printf("Area: %.3f\n", 2*PI*r*(r+h));
}

int main(){
    scanf("%f %d", &r, &h);
    showArea(r,h);
    return 0;
}