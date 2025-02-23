#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    cin >> s;
    bool changed;
    do
    {
        changed = false;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == 'W' && s[i + 1] == 'A')
            {
                s[i] = 'A';
                s[i + 1] = 'C';
                changed = true;
            }
        }
    } while (changed);
    cout << s << endl;
    return 0;
}
