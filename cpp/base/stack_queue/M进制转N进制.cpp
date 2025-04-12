#include <iostream>

using namespace std;
// 测试用例：
// 输入：M = 10, N = 2, origin = 255，预期输出：11111111
// 输入：M = 10, N = 8, origin = 1023，预期输出：1777
// 10 2 255 11111111

int main()
{
    int N, origin, M;
    int digits[101];
    int top = 0;
    // N和M对应的取值范围为1-10
    cout << "请输入对对应的M和N进制,对应的M进制的数字" << endl;
    cin >> M >> N >> origin;
    if (origin == 0)
        cout << 0 << endl;

    // // 先将M进制转换为10进制
    // int decimal = 0;
    // int temp = origin;
    // int power = 1;
    // while (temp) {
    //     decimal += (temp % 10) * power;
    //     temp /= 10;
    //     power *= M;
    // }

    // 再将10进制转换为N进制
    while (origin)
    {
        digits[++top] = origin % N;
        origin /= N;
    }

    cout << "convert to N base numbers is ";
    for (int i = top; i >= 1; --i)
    {
        cout << digits[i];
    }
    cout << endl;

    return 0;
}