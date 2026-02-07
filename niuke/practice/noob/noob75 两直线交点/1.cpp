/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-06 22:51:04
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-06 23:05:25
 */
#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-9;

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

point findMeetingPoint(line line_A, line line_B) {
    // TODO: 在这里输入你的代码，求直线 line_A 与 line_B 的交点
    double x1 = line_A.point_A.x,y1 = line_A.point_A.y;
    double x2 = line_A.point_B.x,y2 = line_A.point_B.y;
    double x3 = line_B.point_A.x,y3 = line_B.point_A.y;
    double x4 = line_B.point_B.x,y4 = line_B.point_B.y;

    // 两直线方向向量的叉积
    double den = (x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);

    // 如果分母接近0,说明直线平行或重合
    if(abs(den) < EPS){
        return point(-1,-1);
    }

    double t_num = (x3-x1)*(y4-y3) - (y3-y1)*(x4-x3);
    double t = t_num / den;

    double intersect_x = x1 + t*(x2-x1);
    double intersect_y = y1 + t*(y2-y1);

    return point{intersect_x,intersect_y};
}

int main() {
    point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    line AB = line(A, B);
    line CD = line(C, D);
    point ans = findMeetingPoint(AB, CD);
    cout << fixed << setprecision(12) << ans.x << " " << ans.y;
    return 0;
}
