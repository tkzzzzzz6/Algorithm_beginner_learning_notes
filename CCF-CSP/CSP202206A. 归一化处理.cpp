/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 11:03:43
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 11:20:13
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define pb push_back
#define endl '\n'

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    double mean = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mean += a[i];
    }
    mean /= n;

    double D = 0;
    for (auto x : a) {
        D += pow(x - mean, 2);
    }
    D /= n;

    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(6) << (a[i] - mean) / sqrt(D) << endl;
    }

    return 0;
}
