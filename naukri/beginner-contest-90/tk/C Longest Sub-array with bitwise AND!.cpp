#include <bits/stdc++.h>
vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries)
{
    // Write your code here.
    vector<int> results;

    for (int X : queries)
    {
        int maxInd = 0;
        int currentAnd = arr[0]; // 注意：arr[0]对应ARR[1]

        // 从索引1开始（对应ARR[1]）
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0)
            {
                currentAnd = arr[i];
            }
            else
            {
                currentAnd &= arr[i];
            }

            // 如果当前前缀按位与 >= X，更新最大索引
            if (currentAnd >= X)
            {
                maxInd = i + 1; // 转换为1-based索引
            }
        }

        results.push_back(maxInd);
    }

    return results;
}