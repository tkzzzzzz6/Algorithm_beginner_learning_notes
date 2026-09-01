/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 15:14:00
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 15:20:06
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> res;
    int n;
    cin >> n;
    while (n != 1) {
        res.push_back(n);
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n >>= 1;
        }
    }
    cout << 1 << ' ';
    reverse(res.begin(), res.end());
    for (auto x : res) {
        cout << x << ' ';
    }
    return 0;
}
