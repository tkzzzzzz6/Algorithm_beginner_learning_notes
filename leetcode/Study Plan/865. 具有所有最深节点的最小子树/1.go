/**
* Definition for a binary tree node.
a type TreeNode struct {
*     Val int
*     Left *TreeNode
*     Right *TreeNode
* }
*/
func subtreeWithAllDeepest(root *TreeNode) (ans *TreeNode) {
	maxDepth := -1
	var dfs func(*TreeNode, int) int
	dfs = func(node *TreeNode, depth int) int {
		if node == nil {
			maxDepth = max(maxDepth, depth)
			return depth
		}

		leftMaxDepth := dfs(node.Left, depth+1)
		rightMaxDepth := dfs(node.Right, depth+1)

		if leftMaxDepth == rightMaxDepth && leftMaxDepth == maxDepth {
			ans = node
		}

		return max(leftMaxDepth, rightMaxDepth)
	}
	dfs(root, 0)
	return
}
