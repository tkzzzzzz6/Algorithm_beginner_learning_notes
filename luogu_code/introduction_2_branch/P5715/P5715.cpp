#include <iostream>
#include <algorithm>  // 包含 std::sort 函数

using namespace std;

// 定义一个函数来比较三个数并按升序输出
void compare(int a, int b, int c) {
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);  // 对数组进行排序
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    compare(a, b, c);  // 调用函数
    return 0;
}