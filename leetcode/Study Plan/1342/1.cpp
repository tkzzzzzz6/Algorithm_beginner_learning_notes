#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int cnt = 0;
        while(num != 0){
            if(num % 2 == 0){
                num /=2;
                cnt++;
            }
            else{
                num--;
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    int num = 14;
    cout << s.numberOfSteps(num) << " ";
    return 0;
}