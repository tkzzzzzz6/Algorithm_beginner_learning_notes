/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-01 15:15:22
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-01 15:23:05
 */
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    double sum = 0;
    int maxN = -INFINITY, minN = INFINITY;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxN = max(a[i], maxN);
        minN = min(a[i], minN);
        sum += (double)a[i];
    }

    cout << fixed << setprecision(2) << (sum - maxN - minN) / (double)(n - 2);

    return 0;
}
