/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-17 13:13:01
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-17 13:13:03
 */
/*
* @acwing app=acwing.cn id=36 lang=C++
*
* 20. 用两个栈实现队列
*/

// @acwing code start

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1,st2;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!st2.empty()){
            int temp = st2.top();
            st2.pop();
            return temp;
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            if(!st2.empty()){
                int temp = st2.top();
                st2.pop();
                return temp;
            }else{
                return -1;
            }
        }
    }

    /** Get the front element. */
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            if(!st2.empty()){
                return st2.top();
            }else{
                return -1;
            }
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
// @acwing code end
