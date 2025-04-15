#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

int target = 20;

int findTarget(vector<int> &arr1)
{
    int left = 0, right = arr1.size();
    while (left < right)
    {
        int mid = (left + right) >> 2;
        if (arr1[mid] >= target)
        {
            return mid;
        }
        arr1[mid] < target ? left = mid + 1 : right = mid;
    }
    return -1;
}

int main()
{
    // 初始化数组
    vector<int> arr1 = {16, 20, 40, 63, 70, 73, 79, 40, 20, 76};

    // 打印数组
    cout << "第一次生成的数组：";
    for (int num : arr1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "result:" << findTarget(arr1);
    return 0;
}