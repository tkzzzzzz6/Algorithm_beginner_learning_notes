<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <stack>

// 单调栈应用：维护一个从栈底到栈顶单调递减的栈
// 异或性质：利用 a ^ a = 0 的性质，元素入栈时异或其索引，出栈时再次异或相同索引即可移除
// 时间复杂度：O(q)，每个元素最多入栈和出栈各一次
// 空间复杂度：O(q)

using namespace std;

// 节点结构体，存储元素的索引和值
struct Node
{
    int index; // 索引（1-based）
    int value; // 元素值
};

int main()
{
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 读入 n 个元素
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // 单调栈：维护一个单调递减的栈（从栈底到栈顶递减）
    stack<Node> s;

    // 异或和：记录当前栈中所有元素索引的异或值
    long long xor_sum = 0;

    // 遍历每个元素
    for (int i = 0; i < n; ++i)
    {
        int current_val = a[i];  // 当前元素值
        int current_idx = i + 1; // 当前索引（1-based）

        // 维护单调栈：弹出所有小于等于当前值的元素
        // 被弹出的元素意味着找到了它们的"下一个更大元素"
        while (!s.empty() && s.top().value <= current_val)
        {
            // 从异或和中移除被弹出元素的索引（异或两次等于抵消）
            xor_sum ^= s.top().index;
            s.pop();
        }

        // 将当前元素压入栈
        s.push({current_idx, current_val});

        // 将当前元素的索引加入异或和
        xor_sum ^= current_idx;

        // 输出当前的异或和
        // 异或和表示：当前栈中所有元素的索引的异或值
        cout << xor_sum << "\n";
    }

    return 0;
=======
#include <iostream>
#include <vector>
#include <stack>

// 单调栈应用：维护一个从栈底到栈顶单调递减的栈
// 异或性质：利用 a ^ a = 0 的性质，元素入栈时异或其索引，出栈时再次异或相同索引即可移除
// 时间复杂度：O(q)，每个元素最多入栈和出栈各一次
// 空间复杂度：O(q)

using namespace std;

// 节点结构体，存储元素的索引和值
struct Node
{
    int index; // 索引（1-based）
    int value; // 元素值
};

int main()
{
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 读入 n 个元素
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // 单调栈：维护一个单调递减的栈（从栈底到栈顶递减）
    stack<Node> s;

    // 异或和：记录当前栈中所有元素索引的异或值
    long long xor_sum = 0;

    // 遍历每个元素
    for (int i = 0; i < n; ++i)
    {
        int current_val = a[i];  // 当前元素值
        int current_idx = i + 1; // 当前索引（1-based）

        // 维护单调栈：弹出所有小于等于当前值的元素
        // 被弹出的元素意味着找到了它们的"下一个更大元素"
        while (!s.empty() && s.top().value <= current_val)
        {
            // 从异或和中移除被弹出元素的索引（异或两次等于抵消）
            xor_sum ^= s.top().index;
            s.pop();
        }

        // 将当前元素压入栈
        s.push({current_idx, current_val});

        // 将当前元素的索引加入异或和
        xor_sum ^= current_idx;

        // 输出当前的异或和
        // 异或和表示：当前栈中所有元素的索引的异或值
        cout << xor_sum << "\n";
    }

    return 0;
>>>>>>> 6948676579abca6ba4f3824e53edf9bbb7e1b238
}