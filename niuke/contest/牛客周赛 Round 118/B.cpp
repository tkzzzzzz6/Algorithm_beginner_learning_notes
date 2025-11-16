#include <bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

typedef pair<int, int> Point;

auto cmp = [](const Point &a, const Point &b) -> bool
{
    // a_1**2 + a_2**2 > b_1**2 + b_2**2 ->( a_1 + b_1)*(a_1 - b_1) + (a_2 - b_2)*(a_2 + b_2) > 0 -> a>b
    //     return (a.first + b.first) * (a.first - b.first) + (a.second + b.second) * (a.second - b.second) < 0;
    ll da = 1LL * a.first * a.first + 1LL * a.second * a.second;
    ll db = 1LL * b.first * b.first + 1LL * b.second * b.second;
    return da < db;
};

il void solve()
{
    multiset<Point, decltype(cmp)> points(cmp);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        points.insert({x, y});
    }
    auto red = points.begin();
    auto purple = points.rbegin();
    cout << red->first << ' ' << red->second << ' ';
    cout << purple->first << ' ' << purple->second << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    solve();

    return 0;
}