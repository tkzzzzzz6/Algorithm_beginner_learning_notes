#include <iostream>
//DFS深度优先搜索

using namespace std;

string tot;
int n, m;

// 将找到的方案转换为字符串形式并计数
void leijia(int a)
{                   
    int b = 262144;//表示处理到第10中配料
    while (a)
    {
        tot += to_string(a / b);
        tot += ' ';
        a %= b;
        b /= 4;
    }
    tot += '\n';
    m++;
}

// 递归函数，寻找满足条件的方案
void f(int s, int k)
{
    if (s < 1 && k < 262145)
        return;
    if (s > 0 && k > 262144)
        return;
    if (s == 0 && k > 262144)
    {
        leijia(k);
        return;
    }
    f(s - 1, k * 4 + 1);//相当于在四进制末尾添加一个数字,记录每个配料的使用量
    f(s - 2, k * 4 + 2);
    f(s - 3, k * 4 + 3);
}

int main()
{
    cin >> n;
    f(n, 0);
    cout << m << endl << tot;
    return 0;
}