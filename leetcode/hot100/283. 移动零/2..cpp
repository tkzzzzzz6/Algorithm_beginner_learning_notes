#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        int slow = 0,fast = 0;
        while(fast < n)
        {
            if(nums[fast] != 0)
            {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        while(slow <n)
        {
            nums[slow++] = 0;
        }
    }
};
