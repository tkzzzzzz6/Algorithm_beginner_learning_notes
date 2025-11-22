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
    vector<ll> a(n);
    ll mn = (ll)4e18, mx = 0;
    for (int i = 0; i < n;++i)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if(mx == 0)
    {
        cout << 0 << endl;
        return;
    }

    // situation 1: p > mx,b = a
    ll ans = mx - mn;

    // situation 2:p = mx
    ll p = mx;
    ll bmin = (ll)4e18, bmax = 0;
    for (int i = 0; i < n;++i)
    {
        ll r = a[i] % p;
        bmin = min(bmin, r);
        bmax = max(bmax, r);
    }

    ll score_p_eq_max = bmax - bmin;
    ans = max(ans, score_p_eq_max);

    cout << ans << endl;
}

int main()
{
    fastio
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// 使用 unsigned long long 防止溢出，自然溢出相当于对 2^64 取模
typedef unsigned long long ull;
typedef long long ll;

const int MAXN = 1000005;

int n;
int c[MAXN];
int v[MAXN];
int f[MAXN];
int L[MAXN], R[MAXN], cnt[MAXN];
ull w[MAXN];      // 每个颜色的随机哈希值
ull S[MAXN];      // 结构哈希（异或前缀）
ll sum_v[MAXN];   // 题目权值 v 的前缀和

// 定义状态结构体，用于排序和比较
struct State {
    ull s_hash;   // 结构哈希 S
    ull k_hash;   // 内容校验哈希 K = C - E
    int idx;      // 对应的下标

    // 重载小于号用于排序
    bool operator<(const State& other) const {
        if (s_hash != other.s_hash) return s_hash < other.s_hash;
        if (k_hash != other.k_hash) return k_hash < other.k_hash;
        return idx < other.idx;
    }

    // 重载等于号用于判断是否匹配
    bool operator==(const State& other) const {
        return s_hash == other.s_hash && k_hash == other.k_hash;
    }
};

vector<State> states;

int main() {
    // 开启快速 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> f[i];

    // 初始化 L 和 R 数组
    // L 初始化为一个大数，R 初始化为 0
    for (int i = 0; i <= n; ++i) {
        L[i] = n + 2;
        R[i] = 0;
        cnt[i] = 0;
    }

    // 预处理每个颜色的第一次出现 L、最后一次出现 R 和出现次数 cnt
    for (int i = 1; i <= n; ++i) {
        int color = c[i];
        if (L[color] > i) L[color] = i;
        R[color] = i;
        cnt[color]++;
    }

    // 生成随机哈希值
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 0) {
            w[i] = rng();
        }
    }

    // 差分数组用于计算 S
    // point_E 用于计算 E
    vector<ull> diff_S(n + 2, 0);
    vector<ull> point_E(n + 2, 0);

    for (int col = 1; col <= n; ++col) {
        if (cnt[col] == 0) continue;
        
        // 构建 S 的差分：
        // 颜色在 [L[col], R[col]-1] 这一段“间隙”内是活跃的
        // 所以在 L[col] 处异或 w，在 R[col] 处再次异或 w（消除）
        if (L[col] < R[col]) {
            diff_S[L[col]] ^= w[col];
            diff_S[R[col]] ^= w[col];
        }

        // 构建 E 的增量：
        // 在颜色结束的位置 R[col]，记录该颜色的总权重
        // 总权重 = 单个随机值 * 出现次数
        point_E[R[col]] += w[col] * (ull)cnt[col];
    }

    ull curr_S = 0;
    ull curr_C = 0;
    ull curr_E = 0;

    // 放入初始状态 (index 0)
    states.push_back({0, 0, 0});
    sum_v[0] = 0;

    for (int i = 1; i <= n; ++i) {
        // 1. 计算当前位置的结构哈希 S
        curr_S ^= diff_S[i];
        
        // 2. 计算内容前缀和 C
        curr_C += w[c[i]];
        
        // 3. 计算完结前缀和 E
        curr_E += point_E[i];
        
        // 4. 计算校验哈希 K = C - E
        ull curr_K = curr_C - curr_E;

        // 记录状态
        states.push_back({curr_S, curr_K, i});
        
        // 记录权值 v 的前缀和
        sum_v[i] = sum_v[i-1] + v[i];
    }

    // 排序状态
    sort(states.begin(), states.end());

    ll min_val = -1; // -1 代表无穷大

    // 扫描排序后的数组，检查相邻且哈希相同的元素
    for (size_t i = 0; i < states.size() - 1; ++i) {
        if (states[i] == states[i+1]) {
            // 发现相同哈希，说明区间 (states[i].idx, states[i+1].idx] 是合法的
            // 也就是 [states[i].idx + 1, states[i+1].idx]
            int l = states[i].idx + 1;
            int r = states[i+1].idx;

            // 计算价值
            ll current_sum_v = sum_v[r] - sum_v[l-1];
            ll cost = f[r - l + 1];
            ll val = current_sum_v * cost;

            if (min_val == -1 || val < min_val) {
                min_val = val;
            }
        }
    }

    cout << min_val << endl;

    return 0;
}