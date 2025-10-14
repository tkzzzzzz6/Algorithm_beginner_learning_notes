#include <bits/stdc++.h>

class Solution
{
public:
    bool isBalanced(string num)
    {
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if (i % 2 == 0)
            {
                sum += (num[i] - '0');
            }
            else
            {
                sum -= (num[i] - '0');
            }
        }
        return sum == 0;
    }
};