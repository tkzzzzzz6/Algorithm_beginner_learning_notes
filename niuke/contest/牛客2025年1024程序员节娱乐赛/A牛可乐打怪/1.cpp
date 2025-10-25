#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, n;
    cin >> a >> n;

    
    int k_min = (n + a - 1) / a;

    ll dmg1 = (n + k_min - 1) / k_min;
    ll total1 = k_min * dmg1;

    ll dmg2 = (n + k_min) / (k_min + 1);
    ll total2 = (k_min + 1) * dmg2;

    ll best_dmg;
    if (total1 < total2)best_dmg = dmg1;
    else if (total1 > total2)best_dmg = dmg2;
    else {
        best_dmg = max(dmg1, dmg2);
    }
    cout << a - best_dmg;
    return 0;
}
