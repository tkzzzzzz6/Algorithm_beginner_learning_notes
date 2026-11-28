/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-26 19:05:42
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-26 19:12:15
 */
#include <cstddef>
#include <iostream>
#include <string>
#include <sys/stat.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int k;
    cin >> k;
    string s;
    cin >> s;

    for (char &x : s) x = 'A' + (static_cast<int>(x - 'A') + k) % 26;
    cout << s << '\n';
    return 0;
}
