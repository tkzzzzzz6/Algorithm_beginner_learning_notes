//位运算

// 求和

// 计数

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // 初始化一个变量来存储异或操作的结果
        char ret = 0;
        
        // 对字符串s中的所有字符进行异或操作
        // 这将有效地抵消所有成对出现的字符
        for(char c : s){
            ret ^= c;
        }
        
        // 对字符串t中的所有字符进行异或操作
        // 由于t比s多一个字符，这将使我们得到多出的那个字符
        for(char c : t){
            ret ^= c;
        }
        
        // 结果将是字符串t中多出的那个字符
        return ret;
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