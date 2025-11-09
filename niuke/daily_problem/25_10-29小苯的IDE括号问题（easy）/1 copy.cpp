<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 输入括号串的长度n和操作次数k
    int n, k;
    cin >> n >> k;

    // 输入括号串s，其中包含鼠标光标（I）
    string s;
    cin >> s;

    // I代表鼠标光标，l表示光标左侧的括号部分，r表示光标右侧的括号部分
    string I;
    vector<char> l; // 用来存储光标左侧的括号串
    vector<char> r; // 用来存储光标右侧的括号串

    int flag; // 记录鼠标光标的位置

    // 将光标左侧的部分存储到l中
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I') // 找到光标的位置
        {
            flag = i;
            break;
        }
        l.push_back(s[i]); // 存储光标左侧的字符
    }

    // 将光标右侧的部分存储到r中
    for (int i = flag + 1; i < n; i++)
    {
        r.push_back(s[i]); // 存储光标右侧的字符
    }

    int idx1 = l.size(); // idx1指示l中当前有效字符的个数
    int idx2 = 0;        // idx2指示r中当前有效字符的个数

    // 进行k次操作
    while (k--)
    {
        cin >> I; // 输入操作类型（backspace 或 delete）

        // 当输入backspace时，处理光标前的字符
        if (I == "backspace")
        {
            // 如果光标前是左括号，光标后是右括号，则跳过删除配对的括号
            if (!r.empty() && l[idx1 - 1] == '(' && r[idx2] == ')')
            {
                idx2++; // 删除匹配的右括号
            }
            if (idx1 > 0) // 如果光标左侧有字符，则删除
            {
                idx1--; // 删除光标左侧的字符
            }
        }

        // 当输入delete时，删除光标右侧的字符
        else if (I == "delete")
        {
            if (idx2 < r.size()) // 如果右侧还有字符，进行删除
            {
                idx2++; // 删除光标右侧的字符
            }
        }
    }

    // 输出修改后的括号串
    // 输出光标左侧的括号部分
    for (int i = 0; i < idx1; i++)
    {
        cout << l[i];
    }

    // 输出光标的位置（I）
    cout << "I";

    // 输出光标右侧的括号部分
    for (int i = idx2; i < r.size(); i++)
    {
        cout << r[i];
    }

    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 输入括号串的长度n和操作次数k
    int n, k;
    cin >> n >> k;

    // 输入括号串s，其中包含鼠标光标（I）
    string s;
    cin >> s;

    // I代表鼠标光标，l表示光标左侧的括号部分，r表示光标右侧的括号部分
    string I;
    vector<char> l; // 用来存储光标左侧的括号串
    vector<char> r; // 用来存储光标右侧的括号串

    int flag; // 记录鼠标光标的位置

    // 将光标左侧的部分存储到l中
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I') // 找到光标的位置
        {
            flag = i;
            break;
        }
        l.push_back(s[i]); // 存储光标左侧的字符
    }

    // 将光标右侧的部分存储到r中
    for (int i = flag + 1; i < n; i++)
    {
        r.push_back(s[i]); // 存储光标右侧的字符
    }

    int idx1 = l.size(); // idx1指示l中当前有效字符的个数
    int idx2 = 0;        // idx2指示r中当前有效字符的个数

    // 进行k次操作
    while (k--)
    {
        cin >> I; // 输入操作类型（backspace 或 delete）

        // 当输入backspace时，处理光标前的字符
        if (I == "backspace")
        {
            // 如果光标前是左括号，光标后是右括号，则跳过删除配对的括号
            if (!r.empty() && l[idx1 - 1] == '(' && r[idx2] == ')')
            {
                idx2++; // 删除匹配的右括号
            }
            if (idx1 > 0) // 如果光标左侧有字符，则删除
            {
                idx1--; // 删除光标左侧的字符
            }
        }

        // 当输入delete时，删除光标右侧的字符
        else if (I == "delete")
        {
            if (idx2 < r.size()) // 如果右侧还有字符，进行删除
            {
                idx2++; // 删除光标右侧的字符
            }
        }
    }

    // 输出修改后的括号串
    // 输出光标左侧的括号部分
    for (int i = 0; i < idx1; i++)
    {
        cout << l[i];
    }

    // 输出光标的位置（I）
    cout << "I";

    // 输出光标右侧的括号部分
    for (int i = idx2; i < r.size(); i++)
    {
        cout << r[i];
    }

    return 0;
}
>>>>>>> 6948676579abca6ba4f3824e53edf9bbb7e1b238
