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

    double ab = hypot(ax - bx, ay - by);

    // AB竖直,x = ax,h = |cx- ax|
    if (bx == ax) {
        double h = fabs(cx - ax);
        return 0.5 * ab * h;
    }

    // AB水平,y = ay,h = |cy-ay|
    if (by == ay) {
        double h = fabs(cy - ay);
        return 0.5 * ab * h;
    }

    // 一般情况
    double k = (by - ay) / (bx - ax);
    double b = ay - k * ax;
    double h = fabs(k * cx + b - cy) / sqrt(1 + k * k);
    return 0.5 * ab * h;
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
