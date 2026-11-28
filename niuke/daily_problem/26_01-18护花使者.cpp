/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-19 00:23:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-22 11:36:48
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    vector<int> D(n);
    long long sumD = 0LL;
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> D[i];
        sumD += (long long)D[i];
    }

    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    // 这里除法可能出现精度丢失,采用交叉相乘比较
    sort(ids.begin(), ids.end(), [&](const int i, const int j) { return T[i] * D[j] < T[j] * D[i]; });

    long long ans = 0LL;
    for (int i = 0; i < n; ++i) {
        int idx = ids[i];
        sumD -= D[idx];
        ans += 2LL * (long long)T[idx] * sumD;
    }

    cout << ans << endl;
}
