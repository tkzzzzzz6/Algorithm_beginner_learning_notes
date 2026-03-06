#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,q;
    cin >> m >> q;
    vector<int> safe(m+1);
    int ans = 0;
    while(q--){
        int x;int op;
        cin >> op;
        cin >> x;
        if(op == 1){
            if(x+3<= m){
                ++safe[x+3];
                if(safe[x+3] == 1)++ans;
            }
            if(x-3>=1){
                ++safe[x-3];
                if(safe[x-3] == 1)++ans;
            }
        }else{
            if(x+3 <= m){
                --safe[x+3];
                if(safe[x+3] == 0)--ans;
            }
            if(x-3>=1){
                --safe[x-3];
                if(safe[x-3] == 0)--ans;
            }
        }
        cout << ans << '\n';
    }
}
