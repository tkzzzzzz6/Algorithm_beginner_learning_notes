#include <bits/stdc++.h>

using namespace std;

int res= 0;
int n=0;

int main() {
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            for(int k = j+1; k < n; ++k) {
                if(v[i] != v[j] && v[j] != v[k] && v[i] != v[k]) {
                    ++res;
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}
