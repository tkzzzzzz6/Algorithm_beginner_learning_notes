#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--){
        stack<int> st;
        int n;
        cin >> n;

        vector<int> pushed(n+1);
        vector<int> poped(n+1);
        for(int i = 0;i<n;++i){
            cin >> pushed[i];
        }

        for(int i = 0;i<n;++i){
            cin >> poped[i];
        }

        int j = 0;
        for(auto e:pushed){
            st.push(e);
            while( !st.empty() && st.top() == poped[j]){
                ++j;
                st.pop();
            }
        }

        cout << (st.empty() ? "Yes" : "No") << '\n';
    }
}
// 64 位输出请用 printf("%lld")
