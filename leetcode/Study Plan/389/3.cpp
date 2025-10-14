//求和

// 计数

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
// 注意加法和减法的操作的先后次序,字符串t的字符串ASCII码值更大,应该先做加法,再对s字符串做减法,不然得到的值是负数,无法得到对应的正确结果
    char findTheDifference(string s, string t)
    {
        int sum = 0;
        for (char c : t)
        {
            sum += c;
        }
        for (char c : s)
        {
            sum -= c;
        }
        return (char)sum;
    }
};

int main()
{
    Solution sol;
    string s = "abcd";
    string t = "abcde";
    cout << sol.findTheDifference(s, t) << endl; 
    return 0;
}