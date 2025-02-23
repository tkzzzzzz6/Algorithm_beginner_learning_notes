#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n); // 使用vector存储输入的数
    
    // 读入n个数
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 排序
    sort(a.begin(), a.end());

    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // long long sum = a[0]; // 用long long避免溢出
    for(int i = 0; i < n-1; i++) {
        if(a[i]+1 > a[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

}
