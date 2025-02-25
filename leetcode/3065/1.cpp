#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int cnt=0,i=0;
        while(i<nums.size()){
            if(nums[i]<k)
                cnt++;
                i++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    cout << s.minOperations(nums, k) << endl;
    return 0;
}