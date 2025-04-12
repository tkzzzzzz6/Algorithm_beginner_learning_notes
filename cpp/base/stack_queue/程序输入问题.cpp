#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>

using namespace std;
char stack[101];
int top = 0;
// test
// 如：在终端上输入了这样两行字符
// PRKJ##OGRAN#MLX;
// VAR@CONST N : # = 10;
// 则实际有效的是：
// PROGRAM LX;
// CONST N = 10;

int main()
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); ++i)
        {
            switch (str[i])
            {
            case '#':
                --top;
                break;
            case '@':
                top = 0;
                break;
            default:
                stack[++top] = str[i];
                break;
            }
        }
        for (int i = 1; i <= top; ++i)
        {
            cout << stack[i];
        }
        cout << endl;
    }
    return 0;
}