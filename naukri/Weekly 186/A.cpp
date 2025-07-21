#include <bits/stdc++.h> 
int goodnessScore(string s) {
    // 使用数组统计，索引0-25对应a-z，索引26-51对应A-Z
    int count[52] = {0};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']--; // 小写字母
        }
        else if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A']++; // 大写字母
        }
    }

    int goodnessScore = 0;

    for (int i = 0; i < 26; i++)
    {
        int caseCount = count[i];     

        if (caseCount > 0)
        {
            goodnessScore++;
        }
        else
        {
            goodnessScore--;
        }
    }

    return goodnessScore;
}

