#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    // 检查 k=0
    if (n % 8 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    // 枚举 k=1 到 99
    for (int k = 1; k <= 99; k++) {
        // 只需要检查最后3位
        long long new_num;

        if (k < 10) {
            // 添加1位
            new_num = (long long)n * 10 + k;
        }
        else {
            // 添加2位
            new_num = (long long)n * 100 + k;
        }

        // 只检查最后3位（取模1000）
        if (new_num % 8 == 0) {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}