/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 辅助函数，用于前序遍历二叉树
void test(struct TreeNode *root, int *res, int *returnSize)
{
    // 如果当前节点为空，直接返回
    if (root == 0)
    {
        return;
    }

    // 将当前节点的值存入结果数组，并增加数组大小
    res[(*returnSize)++] = root->val;
    // 递归遍历左子树
    test(root->left, res, returnSize);
    // 递归遍历右子树
    test(root->right, res, returnSize);
}

// 主函数：前序遍历二叉树并返回遍历结果
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    // 处理空树情况
    if (root == NULL)
    {
        *returnSize = 0;
        return (int *)malloc(sizeof(int)); // 返回空数组
    }

    // 分配内存（根据实际需求调整大小）
    int *res = (int *)malloc(sizeof(int) * 100);
    if (res == NULL)
    { // 检查内存分配是否成功
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0; // 初始化大小

    // 辅助函数（在函数内部定义）
    void preorder(struct TreeNode * node, int *arr, int *size)
    {
        if (node == NULL)
            return;
        if (*size >= 100)
            return; // 防止数组越界

        arr[*size] = node->val;
        (*size)++;

        preorder(node->left, arr, size);
        preorder(node->right, arr, size);
    }

    // 执行遍历
    preorder(root, res, returnSize);

    return res;
}