
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_set<int> us;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        us.insert(x);
    }

    if (us.find(sum - m) != us.end())cout << "Yes\n";
    else cout << "No\n";

    return 0;
}