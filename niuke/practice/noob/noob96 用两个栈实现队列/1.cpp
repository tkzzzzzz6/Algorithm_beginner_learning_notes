/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-16 00:16:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-16 00:16:55
 */
#include <stack>

using namespace std;
class Solution {
public:
  void push(int node) { stack1.push(node); }

  int pop() {
    if (stack2.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    int node = stack2.top();
    stack2.pop();
    return node;
  }

private:
  stack<int> stack1;
  stack<int> stack2;
};
