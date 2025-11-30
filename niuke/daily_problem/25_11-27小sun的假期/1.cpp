#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> segs;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        // 简单的数据清洗：防止 r > n 的非法数据
        if (r > n) r = n;
        segs.push_back({l, r});
    }

    // 1. 按左端点排序
    sort(segs.begin(), segs.end());

    int max_happy = 0;
    int last_end = 0; // 上一次忙碌结束的时间，初始化为0

    for(auto& seg : segs) {
        int l = seg.first;
        int r = seg.second;

        // 2. 计算空隙：如果当前区间的开始时间 > 上次结束时间 + 1
        // 说明中间有断档，这就是假期
        if(l > last_end + 1) {
            int holiday = l - last_end - 1;
            max_happy = max(max_happy, holiday);
        }

        // 3. 更新结束时间 (取 max 是为了处理区间包含的情况，如 [1,10] 和 [2,5])
        last_end = max(last_end, r);
    }

    // 4. 检查最后一段：从最后一次忙碌结束到第 n 天
    if (last_end < n) {
        max_happy = max(max_happy, n - last_end);
    }

    cout << max_happy << endl;
}

int main()
{
    fastio
    solve();
    return 0;
}
