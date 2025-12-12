#include<string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 进行凯撒解密
     * @param password string字符串 旺仔哥哥的密码
     * @param n int整型 每个字符加密过程中错位的次数
     * @return string字符串
     */
    string decodeWangzai(string password, int n) {
        // write code here
        for(auto &ch : password)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                ch = (ch - 'a' - n % 26 + 26) % 26 + 'a';
            }
        }
        return password;
    }
};
