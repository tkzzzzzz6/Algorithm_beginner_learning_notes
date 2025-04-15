#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

int target = 19;

// 生成固定随机数组的函数
vector<int> generateFixedRandomArray(int size, int minVal, int maxVal)
{
    // 设置固定的种子值
    static const unsigned int SEED = 12345;
    // 使用 mt19937 引擎，它比 rand() 具有更好的随机性
    mt19937 gen(SEED);
    // 创建一个在[minVal, maxVal]范围内的均匀分布
    uniform_int_distribution<int> dis(minVal, maxVal);
    // 生成随机数组
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = dis(gen);
    }

    return arr;
}

int findTarget(vector<int> arr1)
{
    int left = 0, right = arr1.size();
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr1[mid] == target)
            return mid + 1;
        arr1[mid] > target ? right = mid - 1 : left = mid + 1;
    }
    return -1;
}

int main()
{
    // 示例：生成10个范围在[1,100]的随机数
    vector<int> arr1 = generateFixedRandomArray(10, 1, 100);
    sort(arr1.begin(), arr1.end());
    // 打印第一次生成的数组
    cout << "第一次生成的数组：";
    for (int num : arr1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "result:" << findTarget(arr1);
}