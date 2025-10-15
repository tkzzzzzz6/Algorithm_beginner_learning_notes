#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                sum = sum + accounts[i][j];
            }
            if (sum > max)
                max = sum;
        }
        return max;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
    cout << s.maximumWealth(accounts) << endl;
    return 0;
}