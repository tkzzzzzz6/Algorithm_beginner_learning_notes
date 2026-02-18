/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-18 15:24:15
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-18 15:24:19
 */
class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算旺仔哥哥在地铁上的最长停留时间
     * @param t int整型vector 序列  t，表示地铁在相邻两站之间的用时
     * @param s int整型vector 序列 s，表示地铁在每一站的停靠时间
     * @param x int整型 旺仔哥哥想从第 x 站出发
     * @param y int整型 旺仔哥哥想坐到第 y 站
     * @return int整型
     */
    int countLongestSubwayTime(vector<int> &t, vector<int> &s, int x, int y) {
        // write code here
        int ans = 0;
        for (int i = x - 1; i < y - 1; ++i) {
            ans += t[i] + s[i];
        }
        ans += s[y - 1];
        return ans;
    }
};
