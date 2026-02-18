class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算出旺仔哥哥最后会站在哪位小朋友旁边
     * @param a int整型vector 第 i 个小朋友的数字是 a_i
     * @param m int整型 表示旺仔哥哥的移动次数
     * @return int整型
     */
    int stopAtWho(vector<int> &a, int m) {
        // write code here
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        int idx = 0;
        while (m--) {
            long long step = a[idx];
            idx = (idx - (step % n) + n) % n;
        }
        return idx + 1;
    }
};
