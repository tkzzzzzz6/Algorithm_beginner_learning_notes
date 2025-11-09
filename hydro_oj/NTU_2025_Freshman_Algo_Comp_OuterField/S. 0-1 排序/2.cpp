#include <iostream>

// 只包含必要的头文件

int main() {
    // 优化输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    int cnt_0 = 0;
    // 使用一个临时变量 n 来保存原始的 t 值
    int n = t;
    while (t--) {
        int x;
        std::cin >> x;
        if (x == 0) {
            cnt_0++;
        }
    }

    // 使用一个循环完成所有输出
    for (int i = 0; i < n; ++i) {
        // 在输出每个数字之前，先判断是不是第一个数
        // 如果不是第一个数，就先输出一个空格
        if (i > 0) {
            std::cout << ' ';
        }

        // 根据当前是第几个数来决定输出 0 还是 1
        if (i < cnt_0) {
            std::cout << 0;
        } else {
            std::cout << 1;
        }
    }
    std::cout << '\n'; // 最后输出一个换行符

    return 0;
}
