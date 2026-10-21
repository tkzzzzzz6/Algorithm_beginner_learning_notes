#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // a、b 分别表示当前项的分母和分子，首项为 2 / 1。
    long double a = 1, b = 2;
    long double ans = 0;

    int n;
    cin >> n;

    while (n--) {
        // 当前项为 b / a；下一项的分子、分母分别为 a + b、b。
        ans += b / a;
        long double temp = a;
        a = b;
        b = temp + b;
    }

    // 按题意保留两位小数输出。
    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}