/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-22 10:33:30
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-22 10:33:41
 */
// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    string lights;
    cin >> lights;
    for (int i = 0; i < n; ++i) {
        if (lights[i] == '0') {
            for (int j = 0; j < 3; ++j) {
                if (i + j < n) lights[i + j] ^= 1;
            }
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
