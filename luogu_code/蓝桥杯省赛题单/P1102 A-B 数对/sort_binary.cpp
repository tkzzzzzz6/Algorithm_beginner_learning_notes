#include <bits/stdc++.h>

using namespace std;
long a[200001];
long N, C, ans;
int main()
{
    cin >> N >> C;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + N + 1);
    for (int i = 1; i <= N; i++)
    {
        // 使用二分查找计算满足 A-B=C 的数对数量
        // upper_bound 返回第一个大于 a[i]+C 的位置
        // lower_bound 返回第一个大于等于 a[i]+C 的位置
        // 两者相减得到等于 a[i]+C 的元素个数
        ans += ((upper_bound(a + 1, a + N + 1, a[i] + C) - a) - (lower_bound(a + 1, a + N + 1, a[i] + C) - a));
    }
    cout << ans;
    return 0;
}