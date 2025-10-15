#include <bits/stdc++.h>

// 查找第一个等于target的位置
int findFirst(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            right = mid - 1; // 继续在左半部分查找
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}
// 查找最后一个等于target的位置
int findLast(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            left = mid + 1; // 继续在右半部分查找
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

// 计算F(X)值
int calculateFX(vector<int> &arr, int X)
{
    int n = arr.size();

    // 找到X的第一个和最后一个位置
    int first = findFirst(arr, X);
    int last = findLast(arr, X);

    if (first == -1)
        return 0; // X不在数组中

    // S = 严格小于X的元素个数 = first
    // G = 严格大于X的元素个数 = n - last - 1
    int S = first;
    int G = n - last - 1;

    return S + G;
}

int maxFXVI(int n, vector<int> &arr)
{
    int maxF = 0;

    // 遍历数组中的每个不同元素
    for (int i = 0; i < n; i++)
    {
        // 跳过重复元素
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int X = arr[i];
        int F = calculateFX(arr, X);
        maxF = max(maxF, F);
    }
    return maxF;
}








