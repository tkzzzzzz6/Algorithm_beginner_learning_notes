#include <iostream>
#include <cmath>

using namespace std;

// 定义find函数，计算p * 2 * (p * 2 + 1)
long long find(long long p) {
    return p * 2 * (p * 2 + 1); // 返回计算结果
}

int main() {
    int n;
    cin >> n; // 读取测试用例的数量
    while (n--) { // 对于每个测试用例
        long long t;
        cin >> t; // 读取输入的时间t
        t -= 1; // 减去1以便后续计算
        long long l = 0, r = 1e9; // 初始化二分查找的左右边界
        
        // 二分查找，寻找合适的l
        while (l < r) {
            long long mid = (l + r) >> 1; // 计算中间值
            if (find(mid) <= t) { // 如果find(mid)小于等于t
                l = mid; // 更新左边界
            } else {
                r = mid - 1; // 更新右边界
            }
            if (l == r - 1) { // 检查是否接近收敛
                if (find(r) <= t) { // 再次检查右边界
                    l = r; // 更新左边界
                }
                break; // 退出循环
            }
        }
        
        t -= find(l); // 更新t的值
        
        // 根据t的值输出对应的坐标
        if (t <= l * 2 + 1) { // 判断t是否在第一段
            cout << t - l << " " << l << endl; // 输出坐标
        } else if (t <= l * 4 + 2) { // 判断t是否在第二段
            cout << l + 1 << " " << (l * 3 - t + 1) << endl; // 输出坐标
        } else if (t <= l * 6 + 4) { // 判断t是否在第三段
            cout << l * 5 + 3 - t << " " << (-l - 1) << endl; // 输出坐标
        } else { // t在第四段
            cout << -l - 1 << " " << (t - l * 7 - 5) << endl; // 输出坐标
        }
    }
    return 0; // 返回0表示程序成功结束
}
