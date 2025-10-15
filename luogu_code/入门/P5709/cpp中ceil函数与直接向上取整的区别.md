# 一、cpp整数除法舍弃小数部分的特性
在 C++ 中，整数除法会舍弃小数部分，只保留整数部分。
通过以下代码来验证这一点：
```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 20;
    int b = 3;
    int result = a / b;
    cout << "20 / 3 = " << result << endl;  // 输出 6
    return 0;
}
```
运行这段代码会输出：
```cpp
20 / 3 = 6
```
# 二、这道P5709题目中向上取整与ceil函数使用
## 1. 使用浮点数除法并向上取整：将除法结果转换为浮点数，然后使用 ceil 函数进行向上取整。
```cpp
#include <iostream>
#include <cmath>  // 包含cmath头文件以使用ceil函数

using namespace std;

int main(){
    int m, t, s;
    cin >> m >> t >> s;
    if (t != 0) {
        int eaten_apples = static_cast<int>(ceil(static_cast<double>(s) / t));  // 使用ceil函数进行向上取整
        int remaining_apples = m - eaten_apples;
        cout << max(remaining_apples, 0) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
```

## 2. 使用整数运算实现向上取整：通过调整被除数来实现向上取整。
```cpp
#include <iostream>

using namespace std;

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
}
```

## 3.比较
- **直接整数运算 (s + t - 1) / t**：

    - 优点：不需要额外的头文件，计算速度快，适用于整数运算。
    - 缺点：需要手动调整被除数，可能不直观。
- **使用 ceil 函数**：

    - 优点：代码直观，易于理解。
    - 缺点：需要包含 cmath 头文件，涉及浮点数运算，可能会有微小的性能开销。
在大多数情况下，直接使用 (s + t - 1) / t 进行整数运算会更高效，因为它避免了浮点数运算的开销。然而，如果代码的可读性和直观性更重要，使用 ceil 函数也是一个不错的选择。