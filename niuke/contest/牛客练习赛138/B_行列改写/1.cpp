#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> r(n), c(m);
    for (int i = 0; i < n; ++i)
        cin >> r[i];
    for (int i = 0; i < m; ++i)
        cin >> c[i];
    sort(r.begin(), r.end(), greater<long long>());
    sort(c.begin(), c.end(), greater<long long>());

    long long ans = 0;

    // 枚举操作次数，选择i个行操作，(n+m-i)个列操作
    for (int i = 0; i <= min(n, n + m); ++i)
    {
        int j = n + m - i; // 列覆盖数量
        if (j > m)
            continue; // 列覆盖超过m个，不合法

        // 找出i个最大的行和j个最大的列
        long long sum = 0;

        // 计算总和: 未被列覆盖的i个行的贡献 + j个列的总贡献 - 重叠区域的行贡献
        for (int k = 0; k < i; ++k)
        {
            sum += r[k] * (m - j); // 行未被列覆盖的部分
        }

        for (int k = 0; k < j; ++k)
        {
            sum += c[k] * n; // 列完全覆盖
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}
