'''
Author: tkzzzzzz6
Date: 2026-05-28 13:39:04
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-28 13:46:17
'''
#
# @lc app=leetcode.cn id=208 lang=python3
# @lcpr version=30204
#
# [208] 实现 Trie (前缀树)
#


# @lcpr-template-start

# @lcpr-template-end

# @lc code=start
class Trie:
    def __init__(self):
        self.root = {}

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node:
                node[c] = {}
            node = node[c]
        node['#'] = True
        
    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            if c not in node:
                return False
            node = node[c]
        return '#' in node

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            if c not in node:
                return False
            node = node[c]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end
