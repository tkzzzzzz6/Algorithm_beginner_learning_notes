#include <bits/stdc++.h>

using namespace std;

// 将函数定义移到 main 函数外部
int bracket_match(string &s1, string &s2)
{
    if (s1 == "(" && s2 == ")")
    {
        return 1;
    }
    else if (s1 == "[" && s2 == "]")
    {
        return 1;
    }
    else if (s1 == "{" && s2 == "}")
    {
        return 1;
    }
    return 0;
}

int main()
{
    string bracket;
    cin >> bracket;

    stack<string> bracket_stack;

    for (int i = 0; i < bracket.size(); i++)
    {
        string current(1, bracket[i]); // 将 char 转换为 string

        if (current == "(" || current == "[" || current == "{")
        {
            bracket_stack.push(current);
        }
        else if (current == ")" || current == "]" || current == "}")
        {
            if (bracket_stack.empty())
            {
                cout << "No" << endl;
                return 0;
            }
            if (bracket_match(bracket_stack.top(), current))
            {
                bracket_stack.pop();
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // 最后检查栈是否为空
    if (!bracket_stack.empty())
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}