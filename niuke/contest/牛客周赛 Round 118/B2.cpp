#include <bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

typedef pair<int, int> Point;

ll dist2(const Point &a, const Point &b) {
    return 1LL * pow((a.first - b.first),2) + 1LL*pow((a.second - b.second),2);
};

il void solve()
{
    vector<Point> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    ll best = -inf,red = -1,purple = -1;
    for (int i = 0; i < n;++i)
        for(int j = i + 1; j < n;++j)
            if(dist2(points[i],points[j]) > best){
                best = dist2(points[i], points[j]);
                red = i;
                purple = j;
            }
    cout << points[red].first << ' ' << points[red].second << ' ';
    cout << points[purple].first << ' ' << points[purple].second << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    solve();

    return 0;
}