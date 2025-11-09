#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long ans = 0;

        // 处理n为奇数的情况
        if (n % 2 == 1)
        {
            ans = 1; // 第一步必须减去一个奇数
            n -= k;  // 减去最大的奇数k
        }

        // 此时n一定是偶数（或负数）
        if (n > 0)
        {
            // 计算需要多少次操作将n减到0
            // 每次减去k-1（最大的偶数）
            ans += (n + k - 2) / (k - 1);
        }

        cout << ans << endl;
    }

    return 0;
}
