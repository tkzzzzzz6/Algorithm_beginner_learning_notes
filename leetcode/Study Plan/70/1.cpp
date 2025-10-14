//动态规划,滚动数组

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        int n1 = 0,n2 = 0,n3 = 1;
        for (int i = 1;i<=n;i++){
            n1 = n2;
            n2 = n3;
            n3 = n2 + n1;
        }
        return n3;
    }
};
int main()
{
    Solution s;
    int n = 2;
    cout << s.climbStairs(n);
    return 0;
}