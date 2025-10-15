#include <bits/stdc++.h>

using namespace std;

string greaterParitySubpart(string &s)
{
    int n = s.size();

    // Extract even-subpart (characters at even indices)
    string even_subpart = "";
    for (int i = 0; i < n; i += 2)
    {
        even_subpart += s[i];
    }

    // Extract odd-subpart (characters at odd indices)
    string odd_subpart = "";
    for (int i = 1; i < n; i += 2)
    {
        odd_subpart += s[i];
    }

    // Compare lexicographically and return the greater one
    if (even_subpart > odd_subpart)
    {
        return even_subpart;
    }
    else
    {
        return odd_subpart;
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;

        cout << greaterParitySubpart(S) << endl;
    }

    return 0;
}