// 竞赛头文件模板: 复制此文件作为每道题的起点
// 包含: 常用头文件、快读快写、宏定义、debug 工具
#include <bits/stdc++.h>
using namespace std;

// ---------- 类型别名 ----------
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// ---------- 常量 ----------
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;  // 按题目要求改: 1e9+7 / 998244353
const double PI = acos(-1.0);
const double EPS = 1e-9;

// ---------- 宏 ----------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

// ---------- debug (本地调试输出, 提交时自动失效) ----------
#ifdef LOCAL
#define dbg(...) cerr << "[" #__VA_ARGS__ "]: ", _dbg(__VA_ARGS__)
template <typename T> void _dbg(T&& x) { cerr << x << '\n'; }
template <typename T, typename... Args> void _dbg(T&& x, Args&&... args) {
    cerr << x << ", "; _dbg(args...);
}
#else
#define dbg(...)
#endif

// ---------- 快读快写 (读入量大于 1e5 时比普通 cin 快) ----------
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

void solve() {
    // 每道题的逻辑写在这里, 方便多测
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;   // 多测时取消注释
    while (T--) solve();
    return 0;
}
// 编译: g++ -std=c++17 -O2 -DLOCAL main.cpp
// 提交时去掉 -DLOCAL, debug 输出即被预处理器剔除
