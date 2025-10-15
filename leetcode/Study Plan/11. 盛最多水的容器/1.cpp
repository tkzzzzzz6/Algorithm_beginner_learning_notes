#include <cmath>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            if (area > ans) ans = area;
            if (height[left] < height[right])left++;
            else right--;
        }
        return ans;
    }
};