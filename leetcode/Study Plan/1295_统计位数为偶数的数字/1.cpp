#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int cnt = 0;
        for(int num:nums){
            if(to_string(num).length()%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    return 0;
}