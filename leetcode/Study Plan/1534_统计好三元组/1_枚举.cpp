#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = i + 1; j < arr.size(); ++j)
            {
                for (int k = j + 1; k < arr.size(); ++k)
                {
                    bool judge = (abs(arr[i] - arr[j]) <= a) && (abs(arr[k] - arr[j]) <= b) && (abs(arr[i] - arr[k]) <= c);
                    if (judge)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> arr(6);
    arr = {3, 0, 1, 1, 9, 7};
    cout << s.countGoodTriplets(arr, 7, 2, 3) << endl;
    cout << (s.countGoodTriplets(arr, 7, 2, 3) == 4) << endl;
    return 0;
}