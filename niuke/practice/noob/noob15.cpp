
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    int n,ans = 0;
    cin >> n;

    do {
        ans += n % 10;
    } while (n /= 10);

    cout << ans;

    return 0;
}