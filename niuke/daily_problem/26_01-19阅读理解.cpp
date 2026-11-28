#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, vector<int>> positions;
    int n;cin >> n;
    for(int i = 1;i<=n;++i){ //用1-based编号从1开始
        int len;
        cin >> len;
        while(len--){
            string str;
            cin >> str;
            auto &v = positions[str];
            // 去重,同一篇只记录一次
            if(v.empty() || v.back() != i)
                v.push_back(i);
        }
    }

    int m;
    cin >> m;
    while(m--){
        string str;
        cin >> str;

        auto it = positions.find(str);
        if(it == positions.end()){
            cout << '\n';
            continue;
        }

        const auto &v = it->second;
        for(int k = 0;k<(int)v.size();++k){
            if(k)cout << ' ';
            cout << v[k];
        }
        cout << '\n';
    }
    return 0;
}
