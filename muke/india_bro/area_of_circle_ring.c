#include <stdio.h>
#define pi 3.14
float s;
void area_circle(float r){
    s = pi * r *r;
    return;
}
int main(){
    float r1,r2,s1,s2,s0;
    printf("enter the radius of the first circle\n");
    scanf("%f%f",&r1,&r2);
    area_circle(r1);
    s1 = s;
    area_circle(r2);
    s2 = s;
    s0 = s1 - s2;
    printf("the area of the first circle is %f\n",s1);
    printf("the area of the second circle is %f\n",s2);
    printf("the area of the two circular ring is %f\n",s0);
    return 0;
}