#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    cin.ignore(); // 忽略 cin >> n 后的换行符
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream ss1(line1);
    stringstream ss2(line2);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        ss1 >> a[i];
        ss2 >> b[i];
    }

    vector<int> p(n, 0);
    iota(p.begin(), p.end(), 0);

    ll win = 0LL, lose = 0LL, draw = 0LL;

    do
    {
        int dark = 0, yxl = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > b[p[i]])
                ++dark;
            else if (a[i] < b[p[i]])
                ++yxl;
        }
        if (dark > yxl)
            ++win;
        else if (dark < yxl)
            ++lose;
        else
            ++draw;
    } while (next_permutation(p.begin(), p.end()));

    cout << win << ' ' << lose << ' ' << draw << '\n';
    return 0;
}