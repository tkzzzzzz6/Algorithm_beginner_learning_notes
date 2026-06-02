/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-29 11:43:22
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-29 12:12:42
 */

//  注意每轮map需要clear()
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string password;
    unordered_map<char, int> mp;

    for (int i = 0; i < n; ++i) {
        cin >> password;
        mp.clear();
        int security = 2;
        bool hasChar = false;
        bool hasNumber = false;
        bool hasSpec = false;

        for (auto c : password) {
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) hasChar = true;
            if ('0' <= c && c <= '9') hasNumber = true;
            if (c == '*' || c == '#') hasSpec = true;
            mp[c]++;
            if (mp[c] > 2) security = 1;
        }
        if (hasChar && hasNumber && hasSpec) {
            if (security == 2)
                cout << 2;
            else
                cout << 1;
            cout << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
