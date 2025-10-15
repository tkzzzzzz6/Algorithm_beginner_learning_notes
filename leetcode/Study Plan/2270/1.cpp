#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size(),cnt = 0;
        long long left = 0,right = 0;
        for(int i = 0; i < n; i++){
            right += nums[i];
        }
        for (int i = 0; i < n - 1;++i){
            left += nums[i];
            right -= nums[i];
            if(left >= right)
                ++cnt;
            }
            return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10, 4, -8, 7};
    cout << s.waysToSplitArray(nums) << endl;
    return 0;
}
