/*
 * @lc app=leetcode.cn id=LCR 138 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 138] 有效数字
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool validNumber(string s) {
        //去除首尾空格
        int i = 0;
        while(i < s.size() && s[i] == ' ')++i;
        s = s.substr(i);

        while(s.size() && s.back() == ' ')
            s.pop_back();

        if(s.empty())return false;


        bool numFlag = false; //是否出现过数字
        bool dotFlag = false; //是否出现过小数点
        bool eFlag = false; //是否出现过 e/E

        for(int i = 0;i<s.size();++i){
            //判定为数字
            if(s[i] >= '0' && s[i] <= '9')
                numFlag = true;
            else if(s[i] == '.' && !dotFlag && !eFlag){
                dotFlag = true;
            }else if((s[i] == 'E' || s[i] == 'e') && !eFlag && numFlag){
                eFlag = true;
                numFlag = false; //e 后面必须有数字,这里需要重置 numFlag
            }else if((s[i] == '+' || s[i] == '-') && (i == 0 || s[i-1] == 'e' || s[i-1] == 'E')){
                
            }
            else{
                return false;
            }
        }
        return numFlag;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0"\n
// @lcpr case=end

// @lcpr case=start
// "e"\n
// @lcpr case=end

// @lcpr case=start
// "."\n
// @lcpr case=end

 */
