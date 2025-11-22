#include <iostream>
#include <vector>

using namespace std;

// 直接插入一个元素到已排序的数组中
void insertElement(vector<int> &arr, int size, int element)
{
    int j = size - 1;
    // 将比element大的元素都向后移动一位
    while (j >= 0 && arr[j] > element)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = element; // 插入element到正确位置
}

int main()
{
    ios::sync_with_stdio(false); // 优化输入输出
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(m); // 使用vector存储数据

    // 输入第一个数据
    cin >> arr[0];

    // 边输入边排序
    for (int i = 1; i < m; i++)
    {
        int num;
        cin >> num;
        insertElement(arr, i, num);
    }

    // 输出排序后的结果
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}