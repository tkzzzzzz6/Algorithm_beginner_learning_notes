<!--
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 13:39:04
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 14:00:40
-->
# 208. 实现 Trie(前缀树)

## 题目描述

实现一个前缀树（Trie）类，支持三种操作：
- **初始化**：Trie()。
- **插入**：insert(word) —— 将字符串插入字典。
- **检索**：search(word) —— 完全匹配已插入的字符串返回 true，否则 false。
- **前缀查询**：startsWith(prefix) —— 存在以 prefix 为前缀的已插入字符串则返回 true。

## 思路

- 用节点保存子节点映射和结束标志（is_end）。
- insert：沿字符创建/移动节点，末尾标记 is_end。
- search：沿字符查找，最后判断 is_end。
- startsWith：沿字符查找，能走完则为 true。

Trie 本质上是一个多叉树,用空间换时间,通过遍历字符串,沿着 Trie 走到底,如果中途没有对应的子节点,说明没有这个单词或前缀;如果走到最后,还要检查是否是单词结尾(对于 search)

- 时间复杂度:
  - insert: O($L$), $L$ 是 word 的长度
  - search: O($L$)
  - startsWith: O($L$)
- 空间复杂度：O($N\times \bar L$), $N$ 是插入的单词数量, $\bar L$ 是单词平均长度

### 代码:类实现

```py
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
```

### 代码:字典实现

```py
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
```
