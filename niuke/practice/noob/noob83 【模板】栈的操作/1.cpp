/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 22:37:29
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 22:38:02
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> st;
    int n;
    cin >> n;
    while(n--){
        string op;
        cin >> op;

        if(op == "push"){
            int x;
            cin >> x;
            st.push_back(x);
        }else if(op == "pop"){
            if(!st.empty())
                st.pop_back();
            else
                cout << "Empty" << endl;
        }else if(op == "query"){
            if(!st.empty())
                cout << st[st.size() - 1] << endl;
            else
                cout << "Empty" << endl;
        }else if(op == "size")
            cout << st.size() << endl;
    }
}
