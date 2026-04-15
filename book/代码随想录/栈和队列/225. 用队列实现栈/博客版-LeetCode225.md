---
title: 2026-04-14-LeetCode刷题笔记-225-用队列实现栈
categories:
  - 算法蒟蒻的成长记录
  - LeetCode
date: 2026-04-14
tags:
  - 栈
  - 队列
  - LeetCode-225
  - 数据结构模拟
---

# 2026-04-14-LeetCode刷题笔记-225-用队列实现栈

这道题的目标是：只使用队列操作，实现栈的后进先出行为。

---

## 方法一：双队列

核心思路：

1. `q1` 作为主队列，`q2` 作为备份队列。
2. `pop/top` 时将 `q1` 前 `n-1` 个元素移动到 `q2`。
3. 此时 `q1` 队头就是栈顶元素。
4. `pop` 直接删除该元素。
5. `top` 读取该元素后再放回 `q2`，保证结构不变。

```cpp
class MyStack {
public:
    queue<int> q1, q2;

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) return -1;
        int n = q1.size();
        while (--n) {
            q2.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q1.pop();

        swap(q1, q2);
        while (!q2.empty()) q2.pop();
        return res;
    }

    int top() {
        if (q1.empty()) return -1;
        int n = q1.size();
        while (--n) {
            q2.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q2.push(q1.front());
        q1.pop();

        swap(q1, q2);
        while (!q2.empty()) q2.pop();
        return res;
    }

    bool empty() {
        return q1.empty();
    }
};
```

---

## 方法二：单队列

核心思路：

1. 所有元素都在 `q1`。
2. `pop/top` 时把前 `n-1` 个元素循环到队尾。
3. 剩下的队头就是栈顶。
4. `top` 取值后要放回队尾，保证不删除。

```cpp
class MyStack {
public:
    queue<int> q1;

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) return -1;
        int n = q1.size();
        while (--n) {
            q1.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        if (q1.empty()) return -1;
        int n = q1.size();
        while (--n) {
            q1.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q1.push(q1.front());
        q1.pop();
        return res;
    }

    bool empty() {
        return q1.empty();
    }
};
```

---

## 复杂度

1. `push`：$O(1)$
2. `pop`：$O(n)$
3. `top`：$O(n)$
4. `empty`：$O(1)$

---

## 总结

这题的关键不是 API 写法，而是明确语义：`top` 只能读不能删，`pop` 才删除。把这个区别处理对，队列模拟栈就很稳了。
