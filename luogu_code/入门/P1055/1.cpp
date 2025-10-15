#include <bits/stdc++.h>
using namespace std;
long long i, s, a, b, c, d, m;
char d1;
int main()
{
    scanf("%d-%d-%d-%c", &a, &b, &c, &d1);
    // 这段是精髓
    if (d1 == 'X') // 判断X与10
        d = 10;
    else
        d = d1 - 48;
    m = (a * 1000 + b) * 100000 + c;
    // 过滤中划线
    for (i = 1; i <= 9; i++) // 依次算
    {
        s += m % 10 * (9 - i + 1);
        // 精髓+1
        s %= 11; // 直接求11的余数即可
        m /= 10; // 删除最后一位
    }
    if (s == d)          // 判断是否正确
        cout << "Right"; // 正确就输出
    else                 // 不正确的处理方法
    {
        cout << a << "-" << b << "-" << c << "-";
        if (s == 10) // 同样，注意X和10
            cout << "X";
        else
            cout << s;
    }
    return 0; // 皮一句，必须要打！否则爆0！
}