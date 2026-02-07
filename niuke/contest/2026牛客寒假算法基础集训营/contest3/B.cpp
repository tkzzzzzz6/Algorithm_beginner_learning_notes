#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const int MAX_SQRT = 32000;
vector<int> primes;
bool is_prime[MAX_SQRT + 5];

il void init_primes() {
    fill(is_prime, is_prime + MAX_SQRT + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_SQRT; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_SQRT; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_SQRT; ++i) {
        if (is_prime[i])
            primes.pb(i);
    }
}

il void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    mp.reserve(n);

    bool found = false;
    vector<int> fac;
    fac.reserve(20);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (found || x == 1)
            continue;

        int t = x;
        fac.clear();

        for (auto p : primes) {
            if (1LL * p * p > t) {
                break;
            }
            if (t % p == 0) {
                fac.pb(p);
                while (t % p == 0) {
                    t /= p;
                }
            }
        }
        if (t > 1)
            fac.pb(t);

        for (auto p : fac) {
            if (mp.count(p)) {
                cout << mp[p] << ' ' << x << endl;
                found = true;
                break;
            }
            mp[p] = x;
        }
    }
    if (!found)
        cout << -1 << endl;
}

int main() {
    fastio;
    init_primes();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
