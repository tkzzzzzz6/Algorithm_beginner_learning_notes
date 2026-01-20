#include <iostream>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

ll n, t, a[N], cnt[N][10];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (n > 1)
            a[i] = t % 10;
        else
            a[i] = t; //特判n=1
    }
    cnt[n][a[n]]++; //初始化,dp的起点
    for (int i = n; i > 1; --i) {
        for (int j = 0; j < 10; ++j) {
            cnt[i - 1][(a[i - 1] + j) % 10] = (cnt[i - 1][(a[i - 1] + j) % 10] + cnt[i][j]) % 1000000007;
            cnt[i - 1][(a[i - 1] * j) % 10] = (cnt[i - 1][(a[i - 1] * j) % 10] + cnt[i][j]) % 1000000007;
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << cnt[1][i] << ' ';
    }
    return 0;
}
