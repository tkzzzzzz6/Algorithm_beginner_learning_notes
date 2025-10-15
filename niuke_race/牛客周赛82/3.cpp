#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n); // 使用vector存储输入的数
    vector<long long> b(n);
    // 读入n个数
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 创建一个长度为n的vector数组pairs，每个元素是一个pair对，用于存储数值和原始位置的对应关系
    vector<pair<long long, int>> pairs(n);
    // 遍历原始数组a，将每个数和它的下标位置组成pair对存入pairs数组
    for(int i = 0; i < n; i++){
        pairs[i] = make_pair(a[i], i);
    }

    // 对pairs数组按照第一个元素(数值)进行排序
    sort(pairs.begin(), pairs.end());

    // 遍历排序后的pairs数组，将排序后的位置(i+1)存入数组b的对应原始位置(pairs[i].second)
    for(int i = 0; i < n; i++){
        b[pairs[i].second] = i +1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (pairs[i].first + 1 > pairs[i + 1].first)
        {
            cout << "NO" << endl;
            return 0;
        } 
    }
    cout << "YES" << endl;

    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << endl;


}
