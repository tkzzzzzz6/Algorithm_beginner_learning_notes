/*
高精度运算详解：加法与乘法

在C/C++中处理超大数字的运算时,我们需要使用高精度算法。本文将详细介绍高精度加法和乘法的实现。

1. 高精度加法
高精度加法的基本思路是:
- 将大数以字符串形式存储
- 从低位到高位逐位相加
- 处理进位#include <bits/stdc++.h>
using namespace std;

unsigned long long calc_factorial(int n) {
    unsigned long long s = 1;
    for (int i = 1; i <= n; i++) {
        s *= i;
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    unsigned long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += calc_factorial(i);
    }
    printf("%llu\n", sum);
    return 0;
}
- 最后反转得到结果

示例代码:
*/

// 高精度加法#include <bits/stdc++.h>
using namespace std;

unsigned long long calc_factorial(int n) {
    unsigned long long s = 1;
    for (int i = 1; i <= n; i++) {
        s *= i;
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    unsigned long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += calc_factorial(i);
    }
    printf("%llu\n", sum);
    return 0;
}
string add(string a, string b) {
    string ans;
    int carry = 0;  // 进位
    
    // 补齐位数
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    
    // 从低位到高位计算
    for(int i = a.length()-1; i >= 0; i--) {
        int temp = (a[i]-'0') + (b[i]-'0') + carry;
        carry = temp / 10;
        ans = char(temp % 10 + '0') + ans;
    }
    
    if(carry) ans = "1" + ans;
    return ans;
}

/*
2. 高精度乘法
高精度乘法相对复杂一些:
- 同样以字符串存储大数
- 模拟手工乘法的过程
- 需要处理多次进位
- 最后将所有部分和相加

示例代码:
*/

// 高精度乘法
string multiply(string a, string b) {
    vector<int> result(a.length() + b.length(), 0);
    
    // 从低位到高位相乘
    for(int i = a.length()-1; i >= 0; i--) {
        for(int j = b.length()-1; j >= 0; j--) {
            result[i+j+1] += (a[i]-'0') * (b[j]-'0');
        }
    }
    
    // 处理进位
    for(int i = result.size()-1; i > 0; i--) {
        result[i-1] += result[i] / 10;
        result[i] %= 10;
    }
    
    // 转换为字符串
    string ans;
    int start = 0;
    while(start < result.size()-1 && result[start] == 0) start++;
    for(int i = start; i < result.size(); i++) {
        ans += char(result[i] + '0');
    }
    
    return ans.empty() ? "0" : ans;
}

/*
使用示例:

string num1 = "123456789";
string num2 = "987654321";
string sum = add(num1, num2);      // 高精度加法
string product = multiply(num1, num2); // 高精度乘法

注意事项：
1. 输入字符串需要合法（只包含数字）
2. 可以根据需要添加输入验证
3. 对于特殊情况（如0）需要特殊处理
4. 实际应用中可能需要处理负数

这些算法的时间复杂度：
- 加法：O(max(len1, len2))
- 乘法：O(len1 * len2)

以上就是高精度加法和乘法的基本实现，可以根据具体需求进行优化和扩展。
*/

