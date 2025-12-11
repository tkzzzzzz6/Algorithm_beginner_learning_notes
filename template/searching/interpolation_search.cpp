/*
 * 插值查找 (Interpolation Search)
 * 用途：在均匀分布的有序数组中查找元素
 * 平均时间复杂度：O(log log n)
 * 最坏时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 优势：比二分查找更快（当数据均匀分布时）
 */

#include <bits/stdc++.h>
using namespace std;

// 插值查找实现
int interpolationSearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target) return left;
            return -1;
        }

        // 计算插值位置
        int pos = left + ((double)(right - left) /
                         (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1;
}

// 使用示例
int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int target = 70;
    int index = interpolationSearch(arr, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }

    return 0;
}
