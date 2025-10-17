#include <iostream>
#include <vector>
#include <algorithm>
// #include <set>

const int N = 200005;
int bit[N];

void update(int x, int val)
{
    for (; x < N; x += x & -x)
        bit[x] = std::max(bit[x], val);
}

int query(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
        res = std::max(res, bit[x]);
    return res;
}

using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        int n = 0;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            bit[i] = 0;
        int res = 0;
        for (int i = n; i >= 1; --i)
        {
            int maxv = query(a[i] - 1);
            if (maxv > 0)
                res = std::max(res, a[i] + maxv);
            update(a[i], a[i]);
        }
        cout << res << endl;
    }
    return 0;
}