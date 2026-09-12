//分数求和

//题目描述 Time Limit : 1000 ms Memory Limit : 256 mb 有一分数序列： 2 / 1 3 / 2 5 / 3 8 / 5 13 / 8 21 / 13...... 
// 求出这个数列的前N项之和，保留两位小数。
//1 +1 1+1/2 1+2/3 1+3/5
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a = 1, b = 2;
    double ans = 0;

    int n;
    cin >> n;

    while (n--) {
        ans += double(b) / a;
        int temp = a;
        a = b;
        b = temp + b;
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}