// 树状数组类，用于高效处理前缀和查询和单点更新
class FenwickTree
{
private:
    vector<int> tree;  // 树状数组存储结构

public:
    // 构造函数，初始化树状数组大小为size+1，所有元素初始值为0
    FenwickTree(int size) : tree(size + 1, 0) {}

    // 更新操作：在index位置增加delta值
    void update(int index, int delta)
    {
        index++;  // 树状数组从1开始索引
        while (index < tree.size())
        {
            tree[index] += delta;
            index += index & -index;  // 移动到父节点
        }
    }

    // 查询操作：返回[0,index]区间的前缀和
    int query(int index)
    {
        index++;  // 树状数组从1开始索引
        int res = 0;
        while (index > 0)
        {
            res += tree[index];
            index -= index & -index;  // 移动到前一个区间
        }
        return res;
    }
};

class Solution
{
public:
    // 计算好三元组的数量
    // 好三元组定义：在nums1和nums2中相对顺序相同的三元组
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        // pos2[i]表示数字i在nums2中的位置
        vector<int> pos2(n);
        // reversedIndexMapping[i]表示nums2中第i个位置对应的nums1中的位置
        vector<int> reversedIndexMapping(n);
        
        // 建立nums2中数字到位置的映射
        for (int i = 0; i < n; i++)
        {
            pos2[nums2[i]] = i;
        }
        // 建立nums1和nums2的位置对应关系
        for (int i = 0; i < n; i++)
        {
            reversedIndexMapping[pos2[nums1[i]]] = i;
        }

        FenwickTree tree(n);
        long long res = 0;
        
        // 遍历每个数字，计算以该数字为中间元素的好三元组数量
        for (int value = 0; value < n; value++)
        {
            int pos = reversedIndexMapping[value];
            // 计算左侧小于当前数字的元素数量
            int left = tree.query(pos);
            // 将当前数字加入树状数组
            tree.update(pos, 1);
            // 计算右侧大于当前数字的元素数量
            int right = (n - 1 - pos) - (value - left);
            // 累加当前数字作为中间元素的好三元组数量
            res += (long long)left * right;
        }
        return res;
    }
};
