#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 1e6 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

// 前向声明
bool is_ok(int x);

vector<int> build_ans() {
    // 直接用 vector 存储满足条件的所有数字（已自动排序）
    vector<int> res;
    for (int i = 1; i < N; ++i) {
        if (is_ok(i)) {
            res.push_back(i);
        }
    }
    return res;
}

bool is_ok(int x) {
    // 将 int 转换为字符串来处理数字
    string s = to_string(x);
    long long dsum = 0;
    // 计算数字各位之和
    for (char ch : s) {
        dsum += ch - '0';
    }
    // 检查是否以5结尾且数字和能被3整除
    return s.back() == '5' && (dsum % 3 == 0);
}

il void solve() {
    // 直接构建 vector
    vector<int> ans = build_ans();

    // 处理查询
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << ans[x - 1] << endl; 
    }
}

int main() {
    fastio;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
