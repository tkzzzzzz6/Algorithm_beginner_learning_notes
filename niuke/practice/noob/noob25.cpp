
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_niumei_number(int n) {
    if (!(n & 1) && n > 50)return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    if (is_niumei_number(n))cout << "yes\n";
    else cout << "no\n";

    return 0;
}