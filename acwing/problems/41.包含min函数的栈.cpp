/*
* @acwing app=acwing.cn id=90 lang=C++
*
* 41. 包含min函数的栈
*/

// @acwing code start

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st,stmin;
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        if(stmin.empty()){
            stmin.push(x);
        }else{
            stmin.push(min(x,stmin.top()));
        }
    }

    void pop() {
        if(st.empty())return;
        st.pop();
        stmin.pop();
    }

    int top() {
        return st.empty() ? -1 : st.top();
    }

    int getMin() {
        return stmin.empty() ? -1 : stmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @acwing code end
