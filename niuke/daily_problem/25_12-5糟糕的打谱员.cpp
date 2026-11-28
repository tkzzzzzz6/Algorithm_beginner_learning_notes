#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 棋谱长度最大值是 10^5 + 10
const int MAX_N = 100000 + 10; 

// dp[i]: 以原棋谱中第 i 步棋结尾的最长合法子序列长度
// 注意：索引从 1 开始
int dp[MAX_N]; 

// 存储所有的棋步。pair<int, int> 存储 (颜色 c, 劫争编号 a)
// moves[i] 对应原棋谱中的第 i 步
pair<int, int> moves[MAX_N]; 

void solve_on2() {
    int n; 
    if (!(cin >> n)) return;

    // 读取所有棋步
    for (int i = 1; i <= n; ++i) {
        cin >> moves[i].first >> moves[i].second;
    }

    // 初始化dp数组
    memset(dp, 0, sizeof(int) * (n + 1));

    int overall_max_len = 0; // 全局最长合法序列长度

    // **外层循环：计算 dp[i]**
    // 遍历每一手棋 s_i (i 从 1 开始)
    for (int i = 1; i <= n; ++i) {
        int c_i = moves[i].first;   // 当前颜色
        int a_i = moves[i].second;  // 当前劫争编号

        // 1. 任何一步棋本身至少构成一个长度为 1 的序列
        int max_prefix_len = 0; 
        
        // **内层循环：寻找最优前驱 s_j**
        // 遍历 i 之前的所有棋步 s_j (j 从 1 到 i-1)
        for (int j = 1; j < i; ++j) {
            int c_j = moves[j].first;   // 前驱颜色
            int a_j = moves[j].second;  // 前驱劫争编号

            // 检查 s_j 是否是 s_i 的合法前驱
            
            // 规则 1: 颜色必须不同
            bool color_diff = (c_j != c_i); 
            
            // 规则 2: 劫争必须不同
            bool action_diff = (a_j != a_i); 

            if (color_diff && action_diff) {
                // 如果 s_j 是合法前驱，则可以从 dp[j] 转移过来
                // 我们取所有合法前驱中，最长的那个序列长度
                max_prefix_len = max(max_prefix_len, dp[j]);
            }
        }
        
        // **状态转移方程：dp[i] = 1 + max(所有合法 dp[j])**
        // 最终的 dp[i] = 最长前缀长度 + 1 (当前步)
        dp[i] = max_prefix_len + 1;

        // 更新全局最长序列长度
        overall_max_len = max(overall_max_len, dp[i]);
    }
    
    // 输出最终结果
    cout << overall_max_len << "\n";
}

int main() {
    // 禁用同步，加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // 测试组数
    if (!(cin >> T)) return 0;

    while (T--) {
        solve_on2();
    }

    return 0;
}
