#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, n;
    unsigned long long ans = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        if (x != 6 && x != 7)
        {
            ans += 250;
        }
        if (x == 7)
        {
            x = 1;
        }
        else
        {
            x++;
        }
    }
    printf("%llu", ans);
    return 0;
}