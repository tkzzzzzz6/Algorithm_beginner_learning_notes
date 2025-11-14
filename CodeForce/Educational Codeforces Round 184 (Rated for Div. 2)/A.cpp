#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, a;
        cin >> n >> a;
        
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        // 找到 a 的插入位置（第一个 >= a 的位置）
        int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
        
        int left_count = idx;           // 左边元素数量
        int right_count = n - idx;      // 右边元素数量
        
        if (left_count > right_count) {
            cout << a - 1 << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
    
    return 0;
}