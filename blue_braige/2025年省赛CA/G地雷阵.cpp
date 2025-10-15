/*
 * 地雷阵问题 - 计算地雷覆盖的总角度范围
 * 
 * 相关知识：
 * 1. 极坐标与直角坐标转换
 *   - 使用atan2(y,x)计算点(x,y)与x轴的夹角
 *   - 使用sqrt(x^2 + y^2)计算点到原点的距离
 * 
 * 2. 三角函数
 *   - asin(x)计算x的反正弦值
 *   - 用于计算地雷覆盖的扇形角度
 * 
 * 3. 区间合并
 *   - 将重叠的区间合并为更大的区间
 *   - 使用sort对区间按起始角度排序
 *   - 遍历区间，合并重叠部分
 * 
 * 4. 浮点数输出控制
 *   - 使用fixed和setprecision控制输出精度
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
    // 输入地雷数量
    int n;
    cin >> n;
    
    // 存储每个地雷的覆盖角度范围 [起始角度, 结束角度]
    vector<pair<double, double>> radians;
    
    // 处理每个地雷
    for (int i = 0; i < n;++i){
        // 输入地雷坐标(a,b)和半径r
        double a, b, r;
        cin >> a >> b >> r;
        
        // 计算地雷中心与原点连线的角度
        double theta = atan2(b,a);
        // 计算地雷到原点的距离
        double len = sqrt(a * a + b * b);
        // 计算地雷覆盖的扇形角度的一半
        double phi = asin(r / len);
        
        // 存储该地雷的覆盖角度范围
        radians.emplace_back(theta - phi, theta + phi); // 直接在尾部“就地”构造元素，而不是先创建一个临时对象再拷贝或移动进去。
    }
    
    // 按起始角度排序
    sort(radians.begin(), radians.end());
    
    // 初始化合并后的角度范围
    double start = 0, end = 0, sum = 0;
    
    // 合并重叠的角度范围
    for (auto &[l,r]:radians){
        if(l <= end){
            // 当前范围与前一个范围不重叠，累加前一个范围
            end = max(end, r);
        }else{
            sum += end - start;
            start = l;
            end = r;
        }
    }
    
    // 累加最后一个范围
    sum += end - start;
    
    // 输出结果，保留两位小数
    cout << fixed << setprecision(3) << 1 - sum / atan2(1, 0) << endl;
    return 0;
}
