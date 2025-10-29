#include<bits/stdc++.h>
using namespace std;

int n;                      // 铁盘数量
vector<int> target_state;   // 目标状态（实际未使用，因为目标就是 [1,2,3,...,n]）
int max_depth;              // IDA* 当前迭代的最大深度限制

/**
 * 启发式函数：估计从当前状态到目标状态还需要的最少步数
 *
 * 原理：计算"断点"数量
 * - 断点：相邻两个铁盘的编号差不是 1（说明它们在目标状态中不相邻）
 * - 每次翻转最多能消除 2 个断点
 * - 因此：所需步数 ≥ ceil(断点数 / 2)
 *
 * 例如：[3, 1, 2, 4]
 *   - 3 和 1 之间：|3-1|=2 ≠ 1 → 断点
 *   - 1 和 2 之间：|1-2|=1 = 1 → 不是断点
 *   - 2 和 4 之间：|2-4|=2 ≠ 1 → 断点
 *   - 4 不在最后位置(应该在最后) → 断点
 *   总共 3 个断点，估计至少需要 ceil(3/2) = 2 步
 */
int heuristic(const vector<int>& state) {
    int breakpoints = 0;

    // 检查最大值（编号 n）是否在最底部（数组末尾）
    // 如果不在，说明最大值还需要移动，算一个断点
    if (state.back() != n) {
        breakpoints++;
    }

    // 遍历相邻元素，检查它们的编号是否连续
    for (int i = 0; i < n - 1; ++i) {
        // 如果相邻元素编号差不是 1，说明它们在目标状态中不相邻
        // 需要通过翻转来调整，算作一个断点
        if (abs(state[i] - state[i + 1]) != 1) {
            breakpoints++;
        }
    }

    return breakpoints;
}

/**
 * 翻转函数：翻转数组的前 k 个元素
 *
 * @param arr 要翻转的数组（按值传递，不修改原数组）
 * @param k 翻转前 k 个元素
 * @return 翻转后的新数组
 *
 * 例如：flip([3, 1, 2, 4], 3) → [2, 1, 3, 4]
 */
vector<int> flip(vector<int> arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
    return arr;
}

/**
 * 深度优先搜索（DFS）+ 剪枝
 *
 * IDA* 核心：在限定深度内搜索解
 * 剪枝条件：g + h(state) > max_depth，即"已用步数 + 估计剩余步数 > 深度限制"
 *
 * @param state 当前状态（铁盘排列）
 * @param g 从起点到当前状态已经走了多少步（实际代价）
 * @param prev_flip 上一次翻转的位置 k（避免重复翻转，如 翻k → 翻k → 回到原状态）
 * @return 是否在当前深度限制内找到解
 */
bool dfs(const vector<int>& state, int g, int prev_flip) {
    // 计算启发式值：估计还需要多少步
    int h = heuristic(state);

    // 剪枝：如果"已用步数 + 估计步数"超过深度限制，放弃这条路径
    // 这是 IDA* 的核心：用启发式函数来剪枝，避免搜索过深
    if (g + h > max_depth) {
        return false;
    }

    // 目标检测：如果启发式值为 0，说明已经达到目标状态 [1,2,3,...,n]
    // （没有断点 = 所有相邻元素都连续 = 已排序）
    if (h == 0) {
        return true;  // 找到解！
    }

    // 尝试所有可能的翻转操作
    // k=2: 翻转前 2 个元素
    // k=3: 翻转前 3 个元素
    // ...
    // k=n: 翻转整个数组
    for (int k = 2; k <= n; ++k) {
        // 剪枝优化：避免连续两次翻转同一个位置
        // 因为 flip(k) → flip(k) 会抵消，回到原状态，是无效操作
        if (k == prev_flip) continue;

        // 生成新状态：执行翻转操作
        vector<int> next_state = flip(state, k);

        // 递归搜索：在新状态继续搜索
        // g+1: 步数加 1
        // k: 记录这次翻转的位置，下次避免重复翻转
        if (dfs(next_state, g + 1, k)) {
            return true;  // 如果找到解，向上返回
        }
    }

    // 所有可能都试过了，没找到解
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 读取输入
    cin >> n;
    vector<int> start_state_raw(n);    // 原始输入（实际半径值）
    vector<int> sorted_unique(n);      // 用于排序和离散化

    for (int i = 0; i < n; ++i) {
        cin >> start_state_raw[i];
        sorted_unique[i] = start_state_raw[i];
    }

    // ========== 离散化处理 ==========
    // 为什么需要离散化？
    // 原始输入可能是：[87, 75, 19, 49, 46, ...]（实际半径值）
    // 但我们只关心相对大小关系，不关心具体数值
    // 离散化后：将它们映射为 1, 2, 3, ..., n（排名）
    // 这样目标状态就是固定的 [1, 2, 3, ..., n]，便于判断和启发

    // 第一步：排序，得到从小到大的顺序
    sort(sorted_unique.begin(), sorted_unique.end());
    // 例如：[87, 75, 19, ...] → 排序后 → [1, 5, 11, 19, ...]

    // 第二步：建立映射表（原始值 → 排名）
    map<int, int> val_to_rank;
    for (int i = 0; i < n; ++i) {
        val_to_rank[sorted_unique[i]] = i + 1;
        // 最小的值 → 排名 1
        // 次小的值 → 排名 2
        // ...
        // 最大的值 → 排名 n
    }

    // 第三步：将原始状态转换为排名表示
    vector<int> start_state(n);
    for (int i = 0; i < n; ++i) {
        start_state[i] = val_to_rank[start_state_raw[i]];
    }
    // 例如：[87, 75, 19, ...] → [14, 13, 3, ...] (根据大小排名)

    // ========== IDA* 迭代加深搜索 ==========
    // 什么是 IDA*？
    // - 结合了迭代加深（ID）和 A* 搜索
    // - 从深度 d=0 开始，如果找不到解，增加到 d=1, d=2, ...
    // - 每次深度限制内，用 DFS + 启发式剪枝搜索
    // - 优点：空间复杂度低（DFS），时间上有启发式加速

    // 从启发式估计值开始迭代
    // 初始 max_depth = h(start_state)：至少需要这么多步
    for (max_depth = heuristic(start_state); ; ++max_depth) {
        // 在深度限制 max_depth 内搜索
        // 参数：初始状态，已用步数 0，上一次翻转位置 0（表示没有）
        if (dfs(start_state, 0, 0)) {
            // 找到解！输出深度（即最少翻转次数）
            cout << max_depth << endl;
            break;
        }
        // 如果在当前深度找不到，增加深度继续搜索
        // max_depth++ 会在下一次循环执行
    }

    return 0;
}