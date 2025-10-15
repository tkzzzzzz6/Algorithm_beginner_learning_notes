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
    sort(v.begin(),v.end());
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(v[j] == v[j+1])++j;
            res += i*(v.size()-j-1);
        }
    }
    cout << res << endl;

    return 0;
}
