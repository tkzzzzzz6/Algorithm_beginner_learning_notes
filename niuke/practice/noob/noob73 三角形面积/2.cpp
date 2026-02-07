/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-06 21:57:04
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-06 21:57:14
 */
#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point(double A, double B) {
        x = A, y = B;
    }
    point() = default;
};

struct triangle {
    point a, b, c;
    triangle(point A, point B, point C) {
        a = A, b = B, c = C;
    }
    triangle() = default;
};

double getArea(triangle T) {
    // TODO: 计算三角形T的面积
    double ax = T.a.x, ay = T.a.y;
    double bx = T.b.x, by = T.b.y;
    double cx = T.c.x, cy = T.c.y;

    // 向量ab和向量ac的叉积
    double cross = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
    return 0.5 * fabs(cross);
}

int main() {
    int x, y;
    cin >> x >> y;
    point a(x, y);
    cin >> x >> y;
    point b(x, y);
    cin >> x >> y;
    point c(x, y);
    triangle T(a, b, c);
    cout << fixed << setprecision(2) << getArea(T) << endl;
    return 0;
}
