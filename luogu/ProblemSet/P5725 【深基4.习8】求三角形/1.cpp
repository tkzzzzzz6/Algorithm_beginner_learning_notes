#include <iostream>
#include <iomanip> // 用于 setw 和 setfill
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    //  第一部分：打印 n*n 矩阵
    for (int i = 0; i < n; ++i) {     // 行
        for (int j = 1; j <= n; ++j) { // 列
            int num = i * n + j;
            // 使用 setw(2) 占据2个字符宽度, setfill('0') 没满的地方补0
            cout << setfill('0') << setw(2) << num;
        }
        cout << endl; // 一行打印完后再换行
    }

    cout << endl; // 两个图形中间空一行

    //  第二部分：打印三角形
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }

        // 打印数字
        // 原逻辑: while(cnt <= i * (i + 1) / 2) 其实就是打印 i 个数字
        for (int k = 0; k < i; k++) {
            cout << setfill('0') << setw(2) << cnt;
            cnt++;
        }
        cout << endl;
    }

    return 0;
}
