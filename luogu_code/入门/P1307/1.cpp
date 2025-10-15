#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    // 处理负数的情况
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    
    // 特殊情况：如果n为0，直接输出0
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // 反转数字
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    // 输出结果，如果原数是负数，加上负号
    if (isNegative) {
        cout << "-";
    }
    cout << reversed << endl;
    
    return 0;
}
