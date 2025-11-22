#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//采用哈希表的方法
int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    unordered_map<int, bool> seen;
    bool flag = false;

    for (int i = 0; i < n; i++){
        cin >> a[i];

        if (seen.find(a[i] - k) != seen.end() || seen.find(a[i] + k) != seen.end()){
            flag = true;
            break;
        }
        seen[a[i]] = true;
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}