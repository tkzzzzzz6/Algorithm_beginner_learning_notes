#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int n, c,x;
    cin >> n >> c;
    unordered_map<int, int> cnt_map;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++cnt_map[x];
    }
    for (auto& pair : cnt_map) {
        if (cnt_map.count(pair.first + c)) {
			res += pair.second * cnt_map[pair.first + c];
        }
    }
    
    cout << res << endl;
    return 0;
}