#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_set<int> s;
        for(int i  = 0;i<n;++i)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        if (s.size() < n) {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }
    
    return 0;
}
