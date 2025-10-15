//采用组合数学的方法，从左上角到右下角的过程中，一共需要向下m-1次，向右n-1次，所以一共需要走m+n-2次，其中m-1次向下，所以一共有C(m+n-2,m-1)种走法。
//时间复杂度O(min(m,n))，空间复杂度O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int64_t ans = 1;
        for (int i =0;i<min(n,m)-1;i++){
            ans *= n+m-2-i;
            ans /= i +1;
        }
        return ans;
    }
};