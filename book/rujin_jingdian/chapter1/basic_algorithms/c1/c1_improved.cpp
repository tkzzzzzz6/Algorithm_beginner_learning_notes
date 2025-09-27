#include <stdio.h>
#include <math.h>

int main(){
    // const double PI = acos(-1.0); // 使用更精确的PI值
    const double PI = atan(1.0)*4; // 另一种高精度PI定义
    double r, h;
    scanf("%lf %lf", &r, &h); // 使用%lf读取double类型
    printf("Area: %.3f\n", 2 * PI * r * (r + h)); // 计算并输出表面积
    return 0;
}