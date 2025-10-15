#include <bits/stdc++.h>
int goodnessScore(string s)
{
    // Write your code here.
    int goodnessScore = 0;

    int count[26] = {0};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']++;
        }
        else
        {
            count[c - 'A']--;
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        int caseCount = count[i];

        if (caseCount > 0)
            goodnessScore--;
        else if (caseCount < 0)
        {
            goodnessScore++;
        }
        else
        {
            continue;
        }
    }

    return goodnessScore;
}
