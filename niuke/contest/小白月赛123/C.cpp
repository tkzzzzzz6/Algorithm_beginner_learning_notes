#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 0;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n;++i)
            cin >> a[i];

        // spical judge n == 1, d = 0,ascdeing naturally
        if( n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        bool is_inc = true;
        for (int i = 1; i < n;++i)
        {
            if(a[i] <= a[i-1])
            {
                is_inc = false;
                break;
            }
        }
        if(is_inc)
        {
            cout << 0 << endl;
            continue;
        }

        // statically count the number of not ascending positions
        ll cntBad = 0,Dmax = 0;
        for (int i = 1; i < n;++i)
        {
            ll diff = a[i] - a[i - 1];
            if(diff <= 0)
            {
                ++cntBad;
                ll C = 1 - diff;

                if(C > Dmax)
                    Dmax = C;
            }
        }

        if(cntBad > m)
        {
            cout << -1 << endl;
            continue;
        }

        auto check = [&](ll d) -> bool
        {
            ll ops = 0;
            for (int i = 1; i < n;++i)
            {
                ll diff = a[i] - a[i - 1];
                if(diff >= 1)
                    continue;
                ll C = 1 - diff;
                ll need = (C + d - 1) / d; //向上取整ceil(c/d)
                ops += need;
                if(ops > m)
                    return false;
            }
            return ops <= m;
        };

        // binary search ans
        ll l = 1, r = Dmax, ans = Dmax;
        while(l <= r)
        {
            ll mid = (l + r) >> 1;
            if(check(mid))
            {
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}


