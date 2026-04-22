#include <cstdio>
#include <iostream>
#include <set>

// 遍历所有可能的二进制数。
// 检查每个二进制数中连续的“1”对应的“10”相加是否等于70。
// 使用集合确保每个满足条件的组合是唯一的。
// 最后输出满足条件的组合数量。

// 使用标准命名空间
using namespace std;

// 定义最大值常量 (2^30)
const int N = 1 << 30;

// 初始化答案计数器和存储唯一值的集合
int ans;
set<int> s;

int main()
{
    // 遍历所有可能的组合，从0到N-1
    for (int i = 0, j; i < N; ++i)
    {
        int cur = 0; // 当前连续'1'的和
        // 检查每个位置，从0到29
        for (j = 0; j < 30; ++j)
        {
            // 如果i的第j位是1
            if (i & (1 << j))
            {
                // 当前和加10
                if ((cur += 10) == 100)
                    break; // 如果和达到100，停止检查
            }
            else
                cur = 0; // 如果位是0，重置当前和

            // 检查当前和是否等于70
            if (cur == 70)
            {
                // 获取当前位置之前的所有位
                int pre = i & ((1 << (j + 1)) - 1);
                // 如果这个组合之前没有被计数
                if (!s.count(pre))
                {
                    ++ans;         // 增加答案计数
                    s.insert(pre); // 将组合插入集合中
                    // 取消下面注释可以输出调试信息
                    // printf("Case %d:\n",ans);
                    // for (int k=0;k<=j;++k) printf("%d ",(i>>k)&1);
                    // putchar('\n');
                }
            }
        }
    }
    // 打印最终答案并返回
    return printf("%d\n", ans), 0;
}