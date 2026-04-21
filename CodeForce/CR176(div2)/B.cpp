#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // 如果k=n-1，所有元素都会被染色，最后一个染色的元素是剩下的那个
        if (k == n - 1)
        {
            // 找出最小的元素作为最后染色的元素
            long long min_val = *min_element(a.begin(), a.end());
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != min_val || sum == 0)
                {
                    sum += a[i];
                }
            }
            cout << sum << endl;
            continue;
        }

        // 一般情况：尝试不同的初始染色方案
        long long max_cost = 0;

        // 尝试每个元素作为最后染色的元素
        for (int last = 0; last < n; last++)
        {
            // 创建元素值和索引的对
            vector<pair<long long, int>> val_idx;
            for (int i = 0; i < n; i++)
            {
                if (i != last)
                {
                    val_idx.push_back({a[i], i});
                }
            }

            // 按值从大到小排序
            sort(val_idx.rbegin(), val_idx.rend());

            // 选择前k个最大值
            vector<int> selected(n, 0);
            long long initial_sum = 0;
            for (int i = 0; i < k; i++)
            {
                selected[val_idx[i].second] = 1;
                initial_sum += val_idx[i].first;
            }

            // 检查是否能染色所有元素
            bool can_color_all = false;
            vector<int> colored = selected;
            queue<int> q;

            // 将初始蓝色元素加入队列
            for (int i = 0; i < n; i++)
            {
                if (colored[i])
                {
                    q.push(i);
                }
            }

            // BFS扩展染色
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                // 检查左邻居
                if (curr > 0 && !colored[curr - 1])
                {
                    colored[curr - 1] = 1;
                    q.push(curr - 1);
                }

                // 检查右邻居
                if (curr < n - 1 && !colored[curr + 1])
                {
                    colored[curr + 1] = 1;
                    q.push(curr + 1);
                }
            }

            // 检查last是否是最后一个被染色的元素
            int colored_count = 0;
            for (int i = 0; i < n; i++)
            {
                if (colored[i])
                    colored_count++;
            }

            if (colored_count == n && !selected[last])
            {
                // 计算成本
                long long cost = initial_sum + a[last];
                max_cost = max(max_cost, cost);
            }
        }

        // 特殊情况：如果我们可以直接选择所有元素
        if (k == n)
        {
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
            }
            max_cost = max(max_cost, sum);
        }

        cout << max_cost << endl;
    }

    return 0;
}
