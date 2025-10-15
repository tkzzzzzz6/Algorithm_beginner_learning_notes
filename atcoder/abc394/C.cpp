#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<char> chars(s.begin(), s.end());
    bool changed = true;

    while (changed)
    {
        changed = false;
        vector<char> next = chars;

        for (int i = 0; i < chars.size() - 1; i++)
        {
            if (next[i] == 'W' && next[i + 1] == 'A')
            {
                next[i] = 'A';
                next[i + 1] = 'C';
                changed = true;
                i++; // 跳过下一个字符，因为已经处理过了
            }
        }
        chars = next;
    }

    for (char c : chars)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
