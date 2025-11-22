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
const int MAXN = 1000005;


int n;
int c[MAXN];
int v[MAXN];
int f[MAXN];
int L[MAXN],R[MAXN],cnt[MAXN];
ull  W[MAXN];
ull S[MAXN];
ll sum_v[MAXN];

struct state
{
    ull s_hash;
    ull k_hash;
    int idx;

    bool operator<(const state& other) const
    {
        if(s_hash != other.s_hash) return s_hash < other.s_hash;
        if(k_hash != other.k_hash) return k_hash < other.k_hash;
        return idx < other.idx;
    }

    bool operator==(const state& other)
    {
        return s_hash == other.s_hash && k_hash == other.k_hash;
    }
};




il void solve(){
    if(!(cin >> n))return;

    for(int i = 1;i<=n;++i)
        cin >> c[i];
    for(int i = 1;i<=n;++i)
        cin >> v[i];
    for(int i = 1;i<=n;++i)
        cin >> f[i];

    // initialize L and R arrays
    for(int i = 0;i<=n;++i)
    {
        L[i] = n+2;
        R[i] = 0;
        cnt[i] = 0;
    }

    for(int i = 1;i<=n;++i)
    {
        int color = c[i];
        if(L[color] > i) L[color] = i;
        R[color] = i;
        ++cnt[color];
    }

    // generate random hash values for each color
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 1;i<=n;++i)
    {
        if(cnt[i] > 0)
        {
            W[i] = rng();
        }
    }

    // diff array to calculate s
    // point_E to calculate E
    vector<ull> diff_S(n+2,0);
    vector<ull> point_E(n+2,0);

    for(int col = 0;col<=n;++col)
    {
        if(cnt[col] == 0)
            continue;

        if(L[col] < R[col])
        {
            diff_S[L[col]] ^= W[col];
            diff_S[R[col]] ^= W[col];
        }

        
        // constuct the difference of s
        point_E[R[col]] += W[col] * (ull)cnt[col];
    }

    ull curr_S = 0;
    ull curr_C = 0;
    ull curr_E = 0;

    vector<state> states;
    states.reserve(n+1);

    states.push_back({0,0,0});

    sum_v[0] = 0;

    for(int i = 1;i<=n;++i)
    {
        // calculate the hash values for current s
        curr_S ^= diff_S[i];

        curr_C += W[c[i]];

        curr_E += point_E[i];

        ull curr_k = curr_C - curr_E;

        states.push_back({curr_S,curr_k,i});

        sum_v[i] = sum_v[i-1] + v[i];
    }

    sort(states.begin(),states.end());

    ll min_val = -1;

    for(int i = 1;i<(int)states.size();++i)
    {
        if(states[i] == states[i-1])
        {
            int l_idx = states[i-1].idx;
            int r_idx = states[i].idx;

            int len = r_idx - l_idx;
            ll current_sum_v = sum_v[r_idx] - sum_v[l_idx];
            ll cost = f[len];
            ll val = current_sum_v * cost;

            if(min_val == -1 || val < min_val)
            {
                min_val = val;
            }
        }
    }

    cout << min_val << endl;



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
