/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-14 15:13:11
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-15 22:13:33
 */
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] 用队列实现栈
 */

//  使用单个队列实现

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#finclude <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyStack {
public:
    queue<int> q1;
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        int n = q1.size();
        if(n < 1)return -1;
        --n;
        while(n--){
            q1.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        int n = q1.size();
        if(n < 1)return -1;
        --n;
        while(n--){
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

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */
