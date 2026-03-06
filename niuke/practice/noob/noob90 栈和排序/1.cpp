#include <vector>
#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

int main(){
    int n;cin >> n;
    int maxt = n;
    stack<int> st;
    for(int i = 0;i<n;++i){
        int x;cin >> x;
        if(x == maxt){
            cout << x << ' ';
            --maxt;
        }else{
            st.push(x);
        }
    }

    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }

    cout << '\n';

    return 0;
}
