/*
 * 二分查找 (Binary Search)
 * 用途：在有序数组中查找元素、寻找边界
 * 时间复杂度：O(log n)
 * 空间复杂度：O(1)
 * 前提：数组必须有序
 */

#include <bits/stdc++.h>
using namespace std;

// 基础二分查找（查找目标值）
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢出

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // 未找到
}

// 递归版本
int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

// 查找第一个等于target的位置
int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // 继续向左查找
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// 查找最后一个等于target的位置
int findLast(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // 继续向右查找
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// 查找第一个大于等于target的位置（lower_bound）
int lowerBound(vector<int>& arr, int target) {
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

// 查找第一个大于target的位置（upper_bound）
int upperBound(vector<int>& arr, int target) {
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

// 在旋转有序数组中查找
int searchRotated(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // 判断哪一半是有序的
        if (arr[left] <= arr[mid]) {
            // 左半部分有序
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // 右半部分有序
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

// 查找旋转有序数组的最小值
int findMin(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

// 二分答案（查找满足条件的最小/最大值）
// 例：找最小的x使得check(x)为true
bool check(int x) {
    // 自定义检查函数
    return x >= 5;
}

int binarySearchAnswer() {
    int left = 0, right = 1000000;
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(mid)) {
            result = mid;
            right = mid - 1;  // 找更小的
        } else {
            left = mid + 1;
        }
    }

    return result;
}

// 实数二分（查找精度为eps的答案）
double binarySearchReal(double left, double right, double eps = 1e-9) {
    // 例：求sqrt(x)
    double target = 2.0;  // 求sqrt(2)

    while (right - left > eps) {
        double mid = (left + right) / 2;

        if (mid * mid < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return left;
}

// 查找峰值元素
int findPeakElement(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            right = mid;  // 峰值在左边或mid就是峰值
        } else {
            left = mid + 1;  // 峰值在右边
        }
    }

    return left;
}

// 使用示例
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};

    // 基础二分查找
    int target = 7;
    int index = binarySearch(arr, target);
    cout << "Index of " << target << ": " << index << endl;

    // 含重复元素的数组
    vector<int> arr2 = {1, 2, 2, 2, 3, 4, 5};
    cout << "\nFirst occurrence of 2: " << findFirst(arr2, 2) << endl;
    cout << "Last occurrence of 2: " << findLast(arr2, 2) << endl;

    // Lower bound 和 Upper bound
    cout << "\nLower bound of 2: " << lowerBound(arr2, 2) << endl;
    cout << "Upper bound of 2: " << upperBound(arr2, 2) << endl;

    // 旋转数组
    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    cout << "\nSearch 0 in rotated array: " << searchRotated(rotated, 0) << endl;
    cout << "Minimum in rotated array: " << findMin(rotated) << endl;

    // 实数二分
    cout << "\nSquare root of 2: " << fixed << setprecision(9)
         << binarySearchReal(0, 2) << endl;

    // 使用STL
    cout << "\nUsing STL:" << endl;
    auto it1 = lower_bound(arr2.begin(), arr2.end(), 2);
    auto it2 = upper_bound(arr2.begin(), arr2.end(), 2);
    cout << "STL lower_bound: " << (it1 - arr2.begin()) << endl;
    cout << "STL upper_bound: " << (it2 - arr2.begin()) << endl;

    return 0;
}
