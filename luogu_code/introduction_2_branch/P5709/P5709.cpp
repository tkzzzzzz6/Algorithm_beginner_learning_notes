#include <iostream>

using namespace std;
//使用向上取整计算吃掉的苹果数的方法
int main(){
    int m, t, s;
    cin >> m >> t >> s;
    if (t != 0) {
        int eaten_apples = (s + t - 1) / t;  // 向上取整计算吃掉的苹果数
        int remaining_apples = m - eaten_apples;
        cout << max(remaining_apples, 0) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;

// 使用ceil函数计算吃掉的苹果数的方法
// #include <iostream>
// #include <cmath>  // 包含cmath头文件以使用ceil函数

// using namespace std;

// int main(){
//     int m, t, s;
//     cin >> m >> t >> s;
//     if (t != 0) {
//         int eaten_apples = static_cast<int>(ceil(static_cast<double>(s) / t));  // 使用ceil函数进行向上取整
//         int remaining_apples = m - eaten_apples;
//         cout << max(remaining_apples, 0) << endl;
//     } else {
//         cout << 0 << endl;
//     }
//     return 0;
// }
