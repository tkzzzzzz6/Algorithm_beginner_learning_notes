#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int edge[maxn];

int main()
{
    int n;
    cin >> n;
    int ui, vi;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> ui >> vi;
        edge[ui]++;
        edge[vi]++;
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, edge[i]);
    }
    int number = 1;
    while (edge[number] == ans)
    {
        number++;
    }

    if (n <= 2)
        cout << "1 1";
    else
        cout << ans - 1 << ' ' << number;

    return 0;
}
