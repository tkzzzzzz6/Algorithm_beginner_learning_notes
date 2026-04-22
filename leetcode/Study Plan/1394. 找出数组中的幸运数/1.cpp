#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size();++i)
            map[arr[i]]++;
        int max = -1;
        for (auto &[key, value] : map)
            if (key == value)
                max = max > key ? max : key;
        return max;
    }
};