#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // 读取N个字符串
    string s[101];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    // 使用set来存储所有不同的拼接结果
    set<string> result;

    // 遍历所有可能的(i,j)组合，其中i≠j
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            { // 确保选择不同的字符串
                // 拼接S[i]和S[j]
                string concatenated = s[i] + s[j];
                result.insert(concatenated);
            }
        }
    }

    // 输出不同字符串的数量
    cout << result.size() << endl;

    return 0;
}