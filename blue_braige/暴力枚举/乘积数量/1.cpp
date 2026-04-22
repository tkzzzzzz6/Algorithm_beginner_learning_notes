#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;
    ll res = 0;
    for (ll i = 1; i * i * i <= N; ++i)
    {
        for (ll j = i; j * j <= N / i; ++j)
        {
            if (j <= N / (i * j))
                res += (N / (i * j) - j + 1);
        }
    }
    cout << res << endl;
    return 0;
}