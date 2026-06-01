/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-29 15:33:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-29 16:11:42
 */
#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.1415926;

bool inCircle(double x, double y, double r) {
    if (x * x + y * y <= r * r) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    double a;
    cin >> n >> a;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        if (inCircle(x, y, a)) cnt++;
    }

    cout << fixed << setprecision(6) << 4 * static_cast<double>(cnt) / n;

    return 0;
}
