/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 19:17:59
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 19:20:27
 */
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string id = "";
        for (int j = 0; j < 8; ++j) {
            string x;
            cin >> x;
            id += x;
        }
        mp[id]++;
        cout << mp[id] << '\n';
    }
    return 0;
}
