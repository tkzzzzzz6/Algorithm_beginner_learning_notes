/*
 * @acwing app=acwing.cn id=3207 lang=C++
 *
 * 3204. 字符串匹配
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

string get(string s) {
    string rs = "";
    for (auto c : s) {
        rs += tolower(c);
    }
    return rs;
}

int main() {
    string s;
    cin >> s;
    int type;
    ;
    int n;
    cin >> type;
    cin >> n;

    // cout << s << endl;

    while (n--) {
        string s1;
        cin >> s1;
        if (type && s1.find(s) != string::npos)
            cout << s1 << endl; // type == 1,大小写敏感
        else if (!type && get(s1).find(get(s)) != string::npos)
            cout << s1 << endl;
    }
    return 0;
}

// @acwing code end
