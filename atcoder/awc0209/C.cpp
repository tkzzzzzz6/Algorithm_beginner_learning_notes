/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-26 19:32:29
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-26 19:53:55
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    string ans;
    int n = (int)s.size();
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && s[j] == s[j - 1]) ++j;
        int cnt = j - i;
        if (cnt >= k) {
            ans += s[i];
            ans += to_string(cnt);
        } else {
            ans.append(s, i, cnt);
        }
        i = j;
    }
    cout << ans << endl;
    return 0;
}
