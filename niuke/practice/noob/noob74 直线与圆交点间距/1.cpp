/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-06 22:30:57
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-06 22:46:18
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

struct line {
    point point_A, point_B;
    line(point A, point B) {
        point_A = A, point_B = B;
    }
    line() = default;
};

struct Circle {
    point O;
    int r;
    Circle(point A, int B) {
        O = A, r = B;
    }
    Circle() = default;
};

double getDistance(const Circle &circle, const line &l) {
    // 请在这里实现你的代码
    double ax = l.point_A.x, ay = l.point_A.y;
    double bx = l.point_B.x, by = l.point_B.y;
    double ox = circle.O.x, oy = circle.O.y;
    double r = double(circle.r);

    double s = fabs((ax - ox) * (by - oy) - (ay - oy) * (bx - ox));
    double ab = hypot(bx - ax, by - ay);

    double h = s / ab;

    if (h >= r) {
        return 0.0;
    } else if (h == 0) {
        return 2 * r;
    } else {
        return 2 * sqrt(pow(r, 2) - pow(h, 2));
    }
}

int main() {
    double ox, oy, r;
    double x1, y1, x2, y2;

    cin >> ox >> oy >> r;
    cin >> x1 >> y1 >> x2 >> y2;

    point center(ox, oy);
    Circle circle(center, (int)r);

    point p1(x1, y1);
    point p2(x2, y2);
    line l(p1, p2);

    double result = getDistance(circle, l);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
