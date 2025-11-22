#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> events; // (时间, 类型：+1表示开始，-1表示结束)

    // 读取输入并构建事件
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});      // 开始事件
        events.push_back({r + 1, -1}); // 结束事件
    }

    // 排序：先按时间，同一时间先处理结束事件(-1)再处理开始事件(+1)
    sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             if (a.first != b.first)
             {
                 return a.first < b.first; // 时间升序
             }
             return a.second < b.second; // 同一时间，-1优先于+1
         });

    vector<int> result(n + 1, -1); // result[k]表示首次有k个人参与的时间
    int currentCount = 0;

    // 扫描所有事件
    for (const auto &event : events)
    {
        int time = event.first;
        int delta = event.second;

        currentCount += delta;

        // 如果当前人数在有效范围内，且是首次出现
        if (currentCount >= 1 && currentCount <= n && result[currentCount] == -1)
        {
            result[currentCount] = time;
        }
    }

    // 输出结果
    for (int k = 1; k <= n; k++)
    {
        cout << result[k] << endl;
    }

    return 0;
}