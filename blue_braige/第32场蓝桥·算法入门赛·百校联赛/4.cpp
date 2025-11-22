#include <bits/stdc++.h>
#define il inline
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

const long long BIG = 4'000'000'000'000'000'000LL;

il void solve()
{
    long long A, B;
    cin >> A >> B;
    long long total = A + B;
    long long maxK = min(A, B);

    auto eval = [&](long long k) -> long long
    {
        if (k < 0 || k > maxK)
            return BIG;
        return llabs(4 * k - total);
    };

    long long target = total / 4;
    vector<long long> cand = {0, maxK, target - 1, target, target + 1};

    long long ans = BIG;
    for (long long k : cand)
    {
        ans = min(ans, eval(k));
    }
    cout << ans << '\n';
}

// x,y,a-x,b-y
// |2x+2y-a-b| -> 0
// ans = 4t - a - b
// t [0,min(a,b)]
int main()
{
    fastio

        int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}