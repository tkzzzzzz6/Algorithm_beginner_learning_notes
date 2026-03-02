/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 22:34:30
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 22:34:35
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<char> st;
        for(char c:s){
            if(c == 'o'){
                if(!st.empty() && st.back() == 'o'){
                    if(st.size() >= 2 && st[st.size() - 2] == 'O'){
                        st.pop_back();
                        st.pop_back();
                    }else{
                        st.back() ='O';
                    }
                }else{
                    st.push_back('o');
                }
            }else{
                if(!st.empty() && st.back() == 'O'){
                    st.pop_back();
                }else{
                    st.push_back('O');
                }
            }
        }
        for(char c:st)cout << c;
        cout << endl;
    }
}
