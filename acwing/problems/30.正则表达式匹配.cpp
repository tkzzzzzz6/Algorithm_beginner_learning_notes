#include <vector>
/*
* @acwing app=acwing.cn id=28 lang=C++
*
* 30. 正则表达式匹配
*/

// @acwing code start

class Solution {
public:
    vector<vector<int>> f;
    string s,p;
    int n,m;

    bool isMatch(string _s, string _p) {
        s = _s,p = _p;
        n = s.size();
        m = p.size();

        f = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return dp(0,0);
    }

    bool dp(int x,int y){
        if(f[x][y] != -1)return f[x][y];
        if(y == m)
            return f[x][y] = x == n;

        bool first_match = x < n && (s[x] == p[y] || p[y] == '.');

        bool ans;

        if(y+1 < m && p[y+1] == '*'){
            ans = dp(x,y+2) || (first_match && dp(x+1,y));
        }else{
            ans = first_match && dp(x+1,y+1);
        }

        return f[x][y] = ans;
    }
};
// @acwing code end
