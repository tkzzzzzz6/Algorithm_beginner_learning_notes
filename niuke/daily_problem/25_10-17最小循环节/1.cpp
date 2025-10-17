
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    string str;
    cin >> str;

    set<char> s(str.begin(), str.end());
    cout << s.size() << '\n';
    cout.flush();

    return 0;
}