#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */

    void calc(vector<int> &nums,vector<char> &ops){
        if(nums.empty() || nums.size() < 2)return;
        if(ops.empty())return;

        int b = nums.back();nums.pop_back();
        int a = nums.back();nums.pop_back();
        char op = ops.back();ops.pop_back();

        if(op == '+')nums.push_back(a+b);
        else if(op == '-')nums.push_back(a-b);
        else if(op == '*')nums.push_back(a*b);
        else return;
    }

    int solve(string s) {
        // write code here
        vector<int> nums;
        vector<char> ops;

        for(int i = 0;i<s.size();++i){
            char c = s[i];
            if(c == '('){
                ops.push_back(c);
            }else if(c == ')'){
                while(!ops.empty()){
                    if(ops.back() != '('){
                        calc(nums,ops);
                    }else{
                        ops.pop_back();
                        break;
                    }
                }
            }else{
                if(isdigit((unsigned char) c)){
                    int u = 0;
                }
            }
        }


        
    }
};
