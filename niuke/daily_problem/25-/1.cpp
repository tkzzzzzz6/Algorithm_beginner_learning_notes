#include <bits/stdc++.h>

int main()
{
    // 输入两个数字字符串
    std::string a, b;
    std::cin >> a >> b;

    // 获取两个字符串中较长的长度
    int n = std::max(a.size(), b.size());
    // 将两个字符串补齐到相同长度，前面补0
    a = std::string(n - a.size(), '0') + a;
    b = std::string(n - b.size(), '0') + b;

    bool ok = false;     // 标记是否已经开始输出非零数字（用于跳过前导零）
    std::string ans = ""; // 存储结果字符串
    
    // 逐位相加（不考虑进位）
    for (int i = 0; i < n; i += 1)
    {
        int x = a[i] - '0', y = b[i] - '0'; // 将字符转换为数字
        int c = (x + y) % 10;                // 相加后对10取模（不考虑进位）
        
        // 如果当前位不为0，或者已经开始输出非零数字
        if (c || ok)
        {
            ok = true;                   // 标记已经开始输出
            ans += char('0' + c);        // 将数字转换为字符并加入结果
        }
    }

    // 如果结果为空（说明所有位都是0），输出"0"
    if (ans.empty())
    {
        ans = "0";
    }

    // 输出最终结果
    std::cout << ans << "\n";
}
