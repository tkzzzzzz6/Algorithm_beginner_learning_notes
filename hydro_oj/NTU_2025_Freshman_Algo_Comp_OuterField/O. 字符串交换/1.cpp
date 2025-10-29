#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> vec(n+1);  
    for(int i = 1; i < n+1; ++i) {
        cin >> vec[i];
    }
    
    while(m--) {
        int x, y;
        cin >> x >> y;

        if(x >= 1 && x <= n && y >= 1 && y <= n) {
            swap(vec[x], vec[y]);
        }
    }
    
    // 只输出 n 个元素
    for(int i = 1; i < n+1; ++i) {
        cout << vec[i] << '\n';
    }
    
    return 0;
}
