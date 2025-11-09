#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--){
        int n = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n;++i)cin >> a[i];
        set<int> s;
        int res = 0;
        for (int i = n - 1; i >= 0;++i){
            auto it = s.lower_bound(a[i]);
            if(it != s.begin()){
                --it;
                res = max(res, a[i] + *it);
            }
            s.insert(a[i]);
        }
        cout << res << endl;
    }    
    return 0;
}