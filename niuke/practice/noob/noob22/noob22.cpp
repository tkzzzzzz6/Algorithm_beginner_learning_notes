
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_leap_year(int n) {
    if (n % 400 == 0 || n % 4 == 0 && n % 100 != 0)return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    if (is_leap_year(n))cout << "yes\n";
    else cout << "no\n";

    return 0;
}