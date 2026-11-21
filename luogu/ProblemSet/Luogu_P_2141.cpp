/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-03 14:13:39
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-03 14:21:07
 */
#include <iostream>
using namespace std;

const int maxN = 1e5 + 5;
int sum[maxN] = {0};
int a[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[a[i]] = 1;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sum[a[i] + a[j]] == 1) {
                ++res;
                sum[a[i] + a[j]] = 0;
            }
        }
    }

    cout << res;

    return 0;
}
