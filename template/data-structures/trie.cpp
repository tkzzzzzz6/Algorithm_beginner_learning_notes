/*
 * 字典树 / Trie / 前缀树
 * 用途：字符串检索、前缀匹配、字符串统计
 * 时间复杂度：插入/查询 O(L)，L为字符串长度
 * 空间复杂度：O(N*L*26)，N为字符串数量
 */

#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;
        int count;  // 以当前节点为结尾的字符串数量

        TrieNode() : isEnd(false), count(0) {}
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // 插入字符串
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
        node->count++;
    }

    // 查找字符串是否存在
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }

    // 查找是否存在以prefix为前缀的字符串
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

    // 删除字符串
    bool remove(string word) {
        return removeHelper(root, word, 0);
    }

private:
    bool removeHelper(TrieNode* node, string& word, int depth) {
        if (!node) return false;

        if (depth == word.length()) {
            if (!node->isEnd) return false;
            node->isEnd = false;
            node->count--;
            return node->children.empty();
        }

        char c = word[depth];
        if (node->children.find(c) == node->children.end()) {
            return false;
        }

        bool shouldDelete = removeHelper(node->children[c], word, depth + 1);

        if (shouldDelete) {
            delete node->children[c];
            node->children.erase(c);
            return !node->isEnd && node->children.empty();
        }

        return false;
    }
};

// 用于数字的字典树（01 Trie，常用于异或最值问题）
class BinaryTrie {
private:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };

    TrieNode* root;
    static const int MAX_BIT = 31;

public:
    BinaryTrie() {
        root = new TrieNode();
    }

    // 插入数字
    void insert(int num) {
        TrieNode* node = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    // 查找与num异或的最大值
    int findMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // 尽量选择相反的bit
            int toggleBit = 1 - bit;
            if (node->children[toggleBit]) {
                maxXor |= (1 << i);
                node = node->children[toggleBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

// 使用示例
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");

    cout << trie.search("app") << endl;         // 输出: 1 (true)
    cout << trie.search("appl") << endl;        // 输出: 0 (false)
    cout << trie.startsWith("appl") << endl;    // 输出: 1 (true)

    BinaryTrie bt;
    bt.insert(3);  // 011
    bt.insert(10); // 1010
    bt.insert(5);  // 101
    bt.insert(25); // 11001

    cout << bt.findMaxXor(2) << endl;  // 找与2异或的最大值

    return 0;
}
