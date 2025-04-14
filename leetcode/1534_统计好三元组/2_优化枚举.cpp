#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int ans = 0, n = arr.size();
        vector<int> sum(1001, 0);
        // 从j=0开始枚举是因为我们需要构建对应的前缀和数组
        for (int j = 0; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (abs(arr[j] - arr[k]) <= b)
                {
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
                    if (l <= r)
                    {
                        if (l == 0)
                        {
                            ans += sum[r];
                        }
                        else
                        {
                            ans += sum[r] - sum[l - 1];
                        }
                    }
                }
            }
            for (int k = arr[j]; k <= 1000; ++k)
            {
                ++sum[k];
            }
        }
        return ans;
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