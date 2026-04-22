#include <cctype>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定一个后缀表达式，返回它的结果
     * @param str string字符串
     * @return long长整型
     */
    long long legalExp(string str) {
        // write code here
        vector<long long> st;

        for(int i = 0;i<str.size();){
            char c = str[i];

            if(c == '#'){
                ++i;
                continue;
            }

            if(isdigit((unsigned char)c)){
                long long val = 0;
                while(i < str.size() && isdigit((unsigned char)str[i])){
                    val = val * 10 + (str[i] - '0');
                    ++i;
                }
                st.push_back(val);
                continue;
            }else{
                long long b = st.back();st.pop_back();
                long long a = st.back();st.pop_back();

                if(c == '+')st.push_back(a+b);
                else if(c == '-')st.push_back(a-b);
                else st.push_back(a*b);

                ++i;
                continue;
            }
        }

        return (st.size() == 1) ? st.back() : 0;
    }
};
