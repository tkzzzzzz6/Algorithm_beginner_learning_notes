class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断二元一次方程组是否有解
     * @param a int整型 二次项系数
     * @param b int整型 一次项系数
     * @param c int整型 常数项
     * @return bool布尔型
     */
    bool judgeSolutions(int a, int b, int c) {
        // write code here
        double delta = static_cast<double>(b) * static_cast<double>(b) - 4.0 * static_cast<double>(a) * static_cast<double>(c);
        return delta >= 0.0;
    }
};
