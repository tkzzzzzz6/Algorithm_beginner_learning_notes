#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
LL a[200001];
map<LL, LL> m; // 建立一个数字到出现次数的映射 map<num,times>
// A-B=C --> A-C=B
int main()
{
    int n;
    LL c;
    LL ans = 0;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        a[i] -= c;
    }
    for (int i = 1; i <= n; i++)
        ans += m[a[i]];
    cout << ans << endl;
    return 0;
}