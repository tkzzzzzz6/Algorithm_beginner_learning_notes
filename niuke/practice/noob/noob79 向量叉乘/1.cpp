class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算出这两个向量叉乘的结果
     * @param vector1 int整型vector
     * @param vector2 int整型vector
     * @return int整型vector
     */
    vector<int> crossTimes(vector<int> &vector1, vector<int> &vector2) {
        // write code here
        // i j k
        // a1 a2 a3
        // b1 b2 b3
        int a1 = vector1[0], a2 = vector1[1], a3 = vector1[2];
        int b1 = vector2[0], b2 = vector2[1], b3 = vector2[2];
        vector<int> ans = {
            a2 * b3 - b2 * a3,
            -(a1 * b3 - b1 * a3),
            a1 * b2 - b1 * a2,
        };
        return ans;
    }
};
