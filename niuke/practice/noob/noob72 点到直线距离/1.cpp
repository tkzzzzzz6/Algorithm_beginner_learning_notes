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
    // TODO: 计算点P到直线L的距离
    // 常规方法
    double dx = L.point_A.x - L.point_B.x;
    double dy = L.point_A.y - L.point_B.y;
    double k = dy / dx;
    double b1 = L.point_A.y - k*L.point_A.x;
    double distance = fabs(k*P.x - P.y + b1) / sqrt(k*k + 1);
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
