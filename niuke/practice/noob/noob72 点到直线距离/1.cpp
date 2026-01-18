#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point(double A, double B) {
        x = A, y = B;
    }
    point() = default;
};

struct line {
    point point_A, point_B;
    line(point A, point B) {
        point_A = A, point_B = B;
    }
    line() = default;
};

double getDistance(point P, line L) {
    // 计算点P到直线L的距离
    // 使用向量叉积公式: distance = |cross product| / |line length|
    // 这个方法适用于所有情况，包括垂直线和水平线
    double dx = L.point_B.x - L.point_A.x;
    double dy = L.point_B.y - L.point_A.y;
    
    // 计算叉积的绝对值: |(B-A) × (A-P)|
    double crossProduct = fabs(dx * (L.point_A.y - P.y) - (L.point_A.x - P.x) * dy);
    
    // 计算线段长度: |B-A|
    double lineLength = sqrt(dx * dx + dy * dy);
    
    // 距离 = 叉积 / 线段长度
    double distance = crossProduct / lineLength;
    return distance;
}

int main() {
    int a, b, sx, sy, tx, ty;
    cin >> a >> b >> sx >> sy >> tx >> ty;
    point A(sx, sy), B(tx, ty), C(a, b);
    line L(A, B);
    printf("%.2lf", getDistance(C, L));
    return 0;
}
