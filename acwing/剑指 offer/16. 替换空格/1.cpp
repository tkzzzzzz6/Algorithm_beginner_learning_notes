/*
* @acwing app=acwing.cn id=17 lang=C++
*
* 16. 替换空格
*/

// @acwing code start

class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for(auto x:str){
            if(x == ' ')
                res += "%20";
            else{
                res += x;
            }
        }
        return res;
    }
};
// @acwing code end
