/*
 * Lower Bound 和 Upper Bound
 * 用途：查找有序数组中的边界位置
 * Lower Bound: 第一个大于等于target的位置
 * Upper Bound: 第一个大于target的位置
 * 时间复杂度：O(log n)
 */

#include <bits/stdc++.h>
using namespace std;

// 手动实现 lower_bound
int myLowerBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// 手动实现 upper_bound
int myUpperBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// 使用示例和STL对比
int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5, 6};

    int target = 2;
    int lb = myLowerBound(arr, target);
    int ub = myUpperBound(arr, target);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\nTarget: " << target << endl;
    cout << "Lower bound (first >= target): " << lb << endl;
    cout << "Upper bound (first > target): " << ub << endl;
    cout << "Count of " << target << ": " << (ub - lb) << endl;

    return 0;
}
