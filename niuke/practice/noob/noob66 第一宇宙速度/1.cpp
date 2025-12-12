#include<cmath>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算星球的第一宇宙速度
     * @param M double浮点型 星球的质量
     * @param r double浮点型 星球的半径
     * @return double浮点型
     */
    double firstSpeed(double M, double r) {
        // write code here
        const double G = 6.67e-11;
        return sqrt((G*M)/r);
    }
};
