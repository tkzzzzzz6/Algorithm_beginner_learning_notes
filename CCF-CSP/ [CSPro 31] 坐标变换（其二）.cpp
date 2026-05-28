/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 22:11:02
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 07:58:22
 */
#include <cmath>
#include <cstdio>

using namespace std;
const int N = 1e5 + 10;
double op1[N], op2[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    op1[0] = 1.0, op2[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        int type;
        double x;
        scanf("%d%lf", &type, &x);

        if (type == 1) {
            op1[i] = op1[i - 1] * x;
            op2[i] = op2[i - 1];
        } else {
            op1[i] = op1[i - 1];
            op2[i] = op2[i - 1] + x;
        }
    }
    while (m--) {
        int i, j;
        double x, y;
        scanf("%d%d%lf%lf", &i, &j, &x, &y);
        double k = op1[j] / op1[i - 1];

        x = k * x, y = k * y;
        double t = op2[j] - op2[i - 1]; // 这里的t采用的弧度制，不用转化

        // 注意这里计算ty的时候要用之前的x不能用tx,所以要再声明变量
        double tx = x * cos(t) - y * sin(t);
        double ty = x * sin(t) + y * cos(t);

        printf("%.3lf %.3lf\n", tx, ty);
    }

    return 0;
}
