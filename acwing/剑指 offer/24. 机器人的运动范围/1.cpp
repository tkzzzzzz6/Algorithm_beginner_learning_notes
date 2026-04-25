#include <vector>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-17 18:08:33
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-18 16:12:41
 */
/*
* @acwing app=acwing.cn id=22 lang=C++
*
* 24. 机器人的运动范围
*/

// @acwing code start

class Solution {
public:
    int getSingleSum(int x){
        int s = 0;
        while(x)s += x % 10, x/=10;
        return s;
    }

    int getSum(pair<int,int> p){
        return getSingleSum(p.first) + getSingleSum(p.second);
    }


    int movingCount(int threshold, int rows, int cols)
    {
        if(!rows || !cols)return 0;

        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        queue<pair<int,int>> q;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int res = 0;

        q.push({0,0});

        while(q.size()){
            auto t = q.front();
            q.pop();
            int x = t.first,y = t.second;

            if(getSum(t) > threshold || visited[x][y])continue;
            res++;
            visited[x][y] = true;

            for(int i = 0;i<4;++i){
                int nx = x + dx[i],ny = y + dy[i];
                if(0<=nx && nx< rows && 0<=ny && ny < cols)
                    q.push({nx,ny});
            }
        }
        return res;
    }
};
// @acwing code end
