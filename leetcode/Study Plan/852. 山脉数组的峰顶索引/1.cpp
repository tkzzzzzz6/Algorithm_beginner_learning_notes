#include <vector>
using namespace std;
class Solution {
   public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 0, right = arr.size() - 2;
        while (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] < arr[mid + 1])
                left = mid;
            else
                right = mid;
        }
        return right;
    }
};
