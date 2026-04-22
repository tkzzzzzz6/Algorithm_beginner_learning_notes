/*
* @acwing app=acwing.cn id=29 lang=C++
*
* 31. 表示数值的字符串
*/

// @acwing code start

class Solution {
public:
    bool isNumber(string s) {
        // 去除前后空格
        int i = 0;
        // 删除 s 前面的空格
        while(i < s.size() && s[i] == ' ')++i; 
        s = s.substr(i);
        // 删除 s 后面的空格
        while(s.size() && s.back() == ' ')s.pop_back();

        if(s.empty())return false;
        
        bool numFlag = false;
        bool dotFlag = false;
        bool eFlag = false;

        for(int i = 0;i<s.size();++i){
            if(isdigit(s[i]))
                numFlag = true;
            else if(!dotFlag && !eFlag && s[i] == '.')
                dotFlag = true;
            else if(numFlag && !eFlag && (s[i] == 'e' || s[i] == 'E')){
                eFlag = true;
                numFlag = false;
            }else if((s[i] == '+' || s[i] == '-') && (i == 0 || s[i-1] == 'e' || s[i-1] == 'E')){

            }
            else{
                return false;
            }

        }

        return numFlag;
    }
};
// @acwing code end
