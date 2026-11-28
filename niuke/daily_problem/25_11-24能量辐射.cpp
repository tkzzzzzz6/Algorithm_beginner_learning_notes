#include<bits/stdc++.h>
#define il inline
using namespace std;

#define pb push_back
#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> v(n);
    for(int i = 0;i<n;++i)
        cin >> h[i] >> v[i];

    vector<int> l(n,-1);
    vector<int> r(n,-1);
    vector<int> st;

    for(int i = 0;i<n;++i)
    {
        while(!st.empty() && h[st.back()] <= h[i])
            st.pop_back();
        if(!st.empty())
            l[i] = st.back();
        st.push_back(i);
    }

    st.clear();

    for(int i = n -  1;i>= 0;--i)
    {
        while(!st.empty() && h[st.back()] <= h[i])
            st.pop_back();
        if(!st.empty())
            r[i] = st.back();
        st.push_back(i);
    }

    vector<ll> e(n,0LL);
    for(int i = 0;i<n;++i)
    {
        if(l[i] >= 0)
            e[l[i]] += v[i];
        if(r[i] >= 0)
            e[r[i]] += v[i];
    }

    ll ans = *max_element(e.begin(),e.end());

    cout << ans << endl;

}

int main()
{
    fastio
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
