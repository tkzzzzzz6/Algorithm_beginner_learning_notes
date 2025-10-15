#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int cnt = 0;
        //定义一个基于小根堆的优先队列
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        while (minHeap.size() >= 2 && minHeap.top() < k)
        {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            minHeap.push(x * 2 + y);
            cnt++;
            }
        return cnt;
    }
};
int main()
{
    vector<int> nums = {1, 1, 2, 4, 9};
    int k = 20;
    Solution s;
    int result = s.minOperations(nums, k);
    cout << "Minimum operations: " << result << endl;
    return 0;
}