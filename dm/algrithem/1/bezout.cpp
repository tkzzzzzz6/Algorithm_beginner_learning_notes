#include <bits/stdc++.h>
using namespace std;

// 修改为迭代版本的扩展欧几里得算法
int extendedGCD(int a, int b, int &s, int &t) {
    int old_s = 1, s_temp = 0;
    int old_t = 0, t_temp = 1;
    
    while (b != 0) {
        int quotient = a / b;
        
        // 更新系数
        int new_s = old_s - quotient * s_temp;
        int new_t = old_t - quotient * t_temp;
        
        // 交换数值
        old_s = s_temp;
        s_temp = new_s;
        
        old_t = t_temp;
        t_temp = new_t;
        
        // 计算新的a和b
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    s = old_s;
    t = old_t;
    return a;
}

int main() {
    // 添加IO加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a = 2009, b = 1394;
    
    int s, t;
    int gcd = extendedGCD(a, b, s, t);
    
    cout << "最大公约数：" << gcd << "\n";  // 使用换行符代替endl
    cout << a << " * (" << s << ") + " 
         << b << " * (" << t << ") = " << gcd << "\n";
    
    if (a * s + b * t == gcd) {
        cout << "验证成功！\n";
    }
    
    return 0;
} 