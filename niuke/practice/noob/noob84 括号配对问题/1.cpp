/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 22:35:09
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 22:35:15
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    stack<char> st;
    bool ok = true;
    for (char c : s) {
        switch (c) {
        case '(':
        case '[':
        case '{':
            st.push(c);
            break;
        case ')':
            if (st.empty() || st.top() != '(')
                ok = false;
            else
                st.pop();
            break;
        case ']':
            if (st.empty() || st.top() != '[')
                ok = false;
            else
                st.pop();
            break;
        case '}':
            if (st.empty() || st.top() != '{')
                ok = false;
            else
                st.pop();
            break;
        default:
            break;
        }
        if (!ok)
            break;
    }
    ok = ok && st.empty();
    cout << (ok ? "true" : "false") << endl;
}
