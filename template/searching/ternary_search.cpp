/*
 * 三分查找 (Ternary Search)
 * 用途：在单峰/单谷函数中查找极值点
 * 时间复杂度：O(log n)
 * 空间复杂度：O(1)
 * 前提：函数必须是凸函数或凹函数
 */

#include <bits/stdc++.h>
using namespace std;

// 离散三分查找（在数组中查找最大值）
int ternarySearchMax(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (right - left > 2) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] < arr[mid2]) {
            left = mid1;
        } else {
            right = mid2;
        }
    }

    // 在剩余的几个元素中找最大值
    int maxIdx = left;
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }

    return maxIdx;
}

// 连续三分查找（查找函数最大值）
// f(x)是单峰函数
double ternarySearchContinuousMax(function<double(double)> f,
                                   double left, double right,
                                   double eps = 1e-9) {
    while (right - left > eps) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        if (f(mid1) < f(mid2)) {
            left = mid1;
        } else {
            right = mid2;
        }
    }

    return (left + right) / 2;
}

// 连续三分查找（查找函数最小值）
double ternarySearchContinuousMin(function<double(double)> f,
                                   double left, double right,
                                   double eps = 1e-9) {
    while (right - left > eps) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        if (f(mid1) > f(mid2)) {
            left = mid1;
        } else {
            right = mid2;
        }
    }

    return (left + right) / 2;
}

// 整数三分查找
long long ternarySearchIntegerMax(function<long long(long long)> f,
                                   long long left, long long right) {
    while (right - left > 2) {
        long long mid1 = left + (right - left) / 3;
        long long mid2 = right - (right - left) / 3;

        if (f(mid1) < f(mid2)) {
            left = mid1;
        } else {
            right = mid2;
        }
    }

    // 检查剩余的几个点
    long long maxVal = f(left);
    long long result = left;

    for (long long i = left + 1; i <= right; i++) {
        if (f(i) > maxVal) {
            maxVal = f(i);
            result = i;
        }
    }

    return result;
}

// 二维三分查找（查找二元函数的极值）
pair<double, double> ternarySearch2D(function<double(double, double)> f,
                                     double x1, double x2,
                                     double y1, double y2,
                                     double eps = 1e-9) {
    // 先对x三分
    while (x2 - x1 > eps) {
        double mx1 = x1 + (x2 - x1) / 3;
        double mx2 = x2 - (x2 - x1) / 3;

        // 对每个x，再对y三分找最优y
        auto findBestY = [&](double x) {
            double ly = y1, ry = y2;
            while (ry - ly > eps) {
                double my1 = ly + (ry - ly) / 3;
                double my2 = ry - (ry - ly) / 3;

                if (f(x, my1) < f(x, my2)) {
                    ly = my1;
                } else {
                    ry = my2;
                }
            }
            return (ly + ry) / 2;
        };

        double y_mx1 = findBestY(mx1);
        double y_mx2 = findBestY(mx2);

        if (f(mx1, y_mx1) < f(mx2, y_mx2)) {
            x1 = mx1;
        } else {
            x2 = mx2;
        }
    }

    double x = (x1 + x2) / 2;
    double y = ternarySearchContinuousMax([&](double yy) { return f(x, yy); }, y1, y2, eps);

    return {x, y};
}

// 应用：找两点间的最近距离（凸函数）
double findClosestDistance(vector<pair<double, double>>& points,
                           pair<double, double> target) {
    auto distance = [&](size_t idx) {
        double dx = points[idx].first - target.first;
        double dy = points[idx].second - target.second;
        return sqrt(dx * dx + dy * dy);
    };

    int n = points.size();
    int left = 0, right = n - 1;

    // 如果点按某种顺序排列，可以用三分查找
    while (right - left > 2) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (distance(mid1) > distance(mid2)) {
            left = mid1;
        } else {
            right = mid2;
        }
    }

    double minDist = distance(left);
    for (int i = left + 1; i <= right; i++) {
        minDist = min(minDist, distance(i));
    }

    return minDist;
}

// 使用示例
int main() {
    // 离散三分查找
    vector<int> arr = {1, 3, 5, 7, 9, 11, 10, 8, 6, 4};
    int maxIdx = ternarySearchMax(arr);
    cout << "Maximum value at index: " << maxIdx
         << ", value: " << arr[maxIdx] << endl;

    // 连续三分查找 - 找抛物线 f(x) = -(x-3)^2 + 10 的最大值
    auto parabola = [](double x) {
        return -(x - 3) * (x - 3) + 10;
    };

    double maxX = ternarySearchContinuousMax(parabola, 0, 10);
    cout << "\nMaximum of parabola at x = " << fixed << setprecision(6)
         << maxX << ", f(x) = " << parabola(maxX) << endl;

    // 找最小值 - f(x) = (x-5)^2 + 3
    auto parabola2 = [](double x) {
        return (x - 5) * (x - 5) + 3;
    };

    double minX = ternarySearchContinuousMin(parabola2, 0, 10);
    cout << "\nMinimum of parabola at x = " << minX
         << ", f(x) = " << parabola2(minX) << endl;

    // 整数三分
    auto intFunc = [](long long x) {
        return -x * x + 10 * x;
    };

    long long intMaxX = ternarySearchIntegerMax(intFunc, 0, 100);
    cout << "\nInteger maximum at x = " << intMaxX
         << ", f(x) = " << intFunc(intMaxX) << endl;

    // 二维三分查找
    auto func2D = [](double x, double y) {
        return -(x - 3) * (x - 3) - (y - 4) * (y - 4) + 20;
    };

    auto [optX, optY] = ternarySearch2D(func2D, 0, 10, 0, 10);
    cout << "\n2D maximum at (" << optX << ", " << optY << ")"
         << ", f(x,y) = " << func2D(optX, optY) << endl;

    return 0;
}
