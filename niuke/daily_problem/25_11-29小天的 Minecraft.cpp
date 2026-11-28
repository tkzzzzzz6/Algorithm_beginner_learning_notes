#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
typedef long long ll;
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 如果a=0，肯定做不出铜镐（因为至少需要12个铜），直接输出0
    if (a == 0)
    {
        cout << fixed << setprecision(10) << 0.0 << endl;
        return;
    }
    
    double p_a = a / 16.0;
    double p_b = b / 16.0;
    double p_c = c / 16.0;

    double ans = 0;

    // 情况1: 16个都是铜 (做铜镐12 + 铜工作台4)
    // 组合数 C(16, 16) = 1
    ans += pow(p_a, 16);

    // 情况2: 12个铜 + 4个银 (做铜镐12 + 银工作台4)
    // 组合数 C(16, 4) = 1820
    ans += 1820.0 * pow(p_a, 12) * pow(p_b, 4);

    // 情况3: 12个铜 + 4个金 (做铜镐12 + 金工作台4)
    // 组合数 C(16, 4) = 1820
    ans += 1820.0 * pow(p_a, 12) * pow(p_c, 4);

    // 必须加上 fixed 才能保证输出像 0.0000000000 这样的定点小数格式
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
