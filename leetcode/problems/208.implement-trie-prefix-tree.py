#
# @lc app=leetcode.cn id=208 lang=python3
# @lcpr version=30204
#
# [208] 实现 Trie (前缀树)
#


# @lcpr-template-start

# @lcpr-template-end

# @lc code=start
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self._find_node(word)
        return node is not None and node.is_end

    def startsWith(self, prefix: str) -> bool:
        return self._find_node(prefix) is not None

    # 辅助函数:沿字符串走到底,返回最后一个节点或 None
    def _find_node(self,s:str)->TrieNode | None:
        node = self.root
        for c in s:
            if c not in node.children:
                return None
            node = node.children[c]
        return node
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end
