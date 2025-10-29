#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // 计算前缀和
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }

    long long max_token = 0;
    // 枚举所有长度为10的区间
    for (int i = 10; i <= n; ++i)
    {
        max_token = max(max_token, prefix[i] - prefix[i - 10]);
    }
    cout << max_token << endl;
    return 0;
}