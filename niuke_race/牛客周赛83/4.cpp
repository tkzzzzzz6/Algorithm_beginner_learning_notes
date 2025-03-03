#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

// 根据坐标序列分析，甲虫的移动轨迹是
// (0,0) -> (1,0) -> (1,-1) -> (0,-1) -> (-1,-1) -> ... 顺时针螺旋

pair<ll, ll> bugPosition(ll t)
{
    if (t == 1)
        return {0, 0};

    t--; // 从0开始计算移动步数

    // 找出t所在的螺旋层
    // 第n层螺旋包含的格子数为 2*n+1 (n从0开始)
    // 第0层: 1个格子 (0,0)
    // 第1层: 8个格子 - 步数为1,1,2,2
    // 第2层: 16个格子 - 步数为3,3,4,4
    // 第n层: 8*(n+1)个格子 - 步数为2*n+1,2*n+1,2*n+2,2*n+2

    ll n = 0;     // 螺旋层数
    ll total = 0; // 已走过的总步数

    // 二分查找所在的螺旋层
    ll left = 0, right = 1000000;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll steps;
        if (mid == 0)
        {
            steps = 0;
        }
        else
        {
            steps = 4 * mid * (mid + 1); // 总步数 = 2*1 + 2*2 + ... + 2*(2*mid)
        }

        if (steps < t)
        {
            n = mid;
            total = steps;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    ll x = 0, y = 0;

    // 如果不是第0层，计算到达第n层开始位置的坐标
    if (n > 0)
    {
        x = n;
        y = 1 - n; // 第n层起始位置是(n, 1-n)
    }

    ll remaining = t - total;
    ll sides[4] = {0}; // 四个方向的步数

    // 当前层的四个方向步数
    if (n == 0)
    {
        sides[0] = 1; // 右
    }
    else
    {
        sides[0] = 2 * n + 1; // 右
        sides[1] = 2 * n + 1; // 下
        sides[2] = 2 * n + 2; // 左
        sides[3] = 2 * n + 2; // 上
    }

    // 移动方向: 右、下、左、上
    pair<int, int> dirs[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    // 移动剩余步数
    for (int dir = 0; dir < 4; dir++)
    {
        if (remaining <= sides[dir])
        {
            // 在当前方向上移动remaining步
            x += dirs[dir].first * remaining;
            y += dirs[dir].second * remaining;
            break;
        }
        else
        {
            // 移动当前方向的所有步数
            x += dirs[dir].first * sides[dir];
            y += dirs[dir].second * sides[dir];
            remaining -= sides[dir];
        }
    }

    return {x, y};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        ll t;
        cin >> t;

        pair<ll, ll> pos = bugPosition(t);
        cout << pos.first << " " << pos.second << endl;
    }

    return 0;
}
