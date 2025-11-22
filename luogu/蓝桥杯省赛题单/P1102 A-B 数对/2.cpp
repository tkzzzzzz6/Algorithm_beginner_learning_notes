#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    unordered_map<int, int> cnt;
    int x, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        cnt[x]++;
    }
    for (auto &[num, count] : cnt)
    {
        if (cnt.count(num + c))
        {
            ans += count * cnt[num + c];
        }
    }
    cout << ans << endl;
    return 0;
}