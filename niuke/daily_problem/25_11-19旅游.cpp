// FZANOTFOUND
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ne " -> "
#define sep "======"
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<long long, long long> PLL;
typedef tuple<ll, ll, ll> TLLL;
const ll INF = (ll)2e18 + 9;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
const db PI = 3.14159265358979323;

// io functions
inline void rd(ll &x)
{
    x = 0;
    short f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-')
        c = getchar();
    if (c == '-')
        f = -1, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    x *= f;
}
inline ll read()
{
    ll x = 0;
    short f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-')
        c = getchar();
    if (c == '-')
        f = -1, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    x *= f;
    return x;
}
inline void pt(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        pt(x / 10);
    putchar(x % 10 + '0');
}
inline void print(ll x) { pt(x), puts(""); }
inline void print(PLL x) { pt(x.fi), putchar(' '), pt(x.se), putchar('\n'); }
inline void print(vector<ll> &vec)
{
    for (const auto t : vec)
        pt(t), putchar(' ');
    puts("");
}
inline void print(const map<ll, ll> &g)
{
    for (const auto &[key, value] : g)
    {
        cout << "key: " << key << ne << value << " ";
    }
    puts("");
}
inline void print(vector<PLL> &vec)
{
    puts(sep);
    for (const auto v : vec)
    {
        print(v);
    }
    puts(sep);
}
inline void print(const map<ll, vector<ll>> &g)
{
    for (const auto &[key, value] : g)
    {
        cout << "key: " << key << ne;
        for (const auto &v : value)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

// fast pow
ll ksm(ll a, ll b = MOD - 2, ll M = MOD)
{
    a %= M;
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // rng()
ull randint(ull l, ull r)
{
    uniform_int_distribution<unsigned long long> dist(l, r);
    return dist(rng);
}

void init()
{
}
class DSU
{
private:
    vector<ll> parent, rank, size;

public:
    DSU(ll n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);
        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    ll find(ll p)
    {
        if (parent[p] != p)
            parent[p] = find(parent[p]);
        return parent[p];
    }
    void unite(ll p, ll q)
    {
        ll rootP = find(p);
        ll rootQ = find(q);
        if (rootP == rootQ)
            return;
        if (rank[rootP] > rank[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else if (rank[rootP] < rank[rootQ])
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
            rank[rootP] += 1;
        }
    }
    bool connected(ll x, ll y)
    {
        return find(x) == find(y);
    }
    ll getSize(ll p)
    {
        return size[find(p)];
    }
    ll count()
    {
        ll ans = 0;
        for (ll i = 0; i < parent.size(); i++)
        {
            ans += (parent[i] == i);
        }
        return ans;
    }
};

void solve()
{
    ll n = read(), m = read(), c = read();
    vector<array<ll, 3>> egs(m);
    for (ll i = 0; i < m; i++)
    {
        egs[i] = {read(), read(), read()};
    }
    sort(all(egs), [&](array<ll, 3> &a, array<ll, 3> &b)
         { return a[2] < b[2]; });
    DSU dsu(n);
    vector<ll> use;
    for (auto [u, v, w] : egs)
    {
        if (!dsu.connected(u, v))
        {
            use.pb(w);
            dsu.unite(u, v);
        }
    }
    reverse(all(use));
    ll tot = 0;
    for (ll i = 1; i <= use.size(); i++)
    {
        tot += use[i - 1] * i;
        if (tot > c)
        {
            print(use[i - 1]);
            return;
        }
    }
    print(0);
}

int main()
{
    init();
    ll t = 1;
    // t = read();
    while (t--)
    {
        solve();
    }
}
