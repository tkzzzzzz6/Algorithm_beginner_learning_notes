#include <iostream>

using namespace std;
// input:
// 3467
//
// output:
// 6613

int main()
{
    int N, origin;
    int digits[101];
    int top = 0;
    cout << "请输入对一个的进制,对应的数字" << endl;
    cin >> N >> origin;
    if (origin == 0)
        cout << 0 << endl;
    while (origin)
    {
        digits[++top] = origin % N;
        origin /= N;
    }
    cout << "convert to N base numbers is ";
    for (int i = 1; i <= top; ++i)
    {
        cout << digits[i];
    }
    cout << endl;

    return 0;
}