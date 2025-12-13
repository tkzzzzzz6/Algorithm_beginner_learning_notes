/**
 * struct Point {
 *	int x;
 *	int y;
 *	Point(int xx, int yy) : x(xx), y(yy) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算A点与B点之间的距离
     * @param point_A Point类 A点
     * @param point_B Point类 B点
     * @return double浮点型
     */
    double calculateDistance(Point point_A, Point point_B) {
        // write code here
        double dx = static_cast<double>(point_A.x - point_B.x);
        double dy = static_cast<double>(point_A.y - point_B.y);
        return sqrt(dx * dx + dy * dy);
    }
};
