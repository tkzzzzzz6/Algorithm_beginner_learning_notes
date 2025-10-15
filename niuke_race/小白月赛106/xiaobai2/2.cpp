#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 只需要计算一次最大最小值
    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    
    // 直接计算最终平均值和操作次数
    int average = (max_val + min_val + 1) / 2;
    long long cnt = 0;  // 使用long long防止溢出
    
    // 一次性计算所有需要的操作次数
    for (int i = 0; i < n; i++)
    {
        if (a[i] < average)
        {
            cnt = 2 * (average - a[i]) - 1;
        }
        else if (a[i] > average)
        {
            cnt = 2 * (a[i] - average);
        }
    }

    cout << cnt << " " << average << endl;
    return 0;
}