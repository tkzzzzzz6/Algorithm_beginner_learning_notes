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

    // ֻ��Ҫ����һ�������Сֵ
    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    
    // ֱ�Ӽ�������ƽ��ֵ�Ͳ�������
    int average = (max_val + min_val + 1) / 2;
    long long cnt = 0;  // ʹ��long long��ֹ���
    
    // һ���Լ���������Ҫ�Ĳ�������
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