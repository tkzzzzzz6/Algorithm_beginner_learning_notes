#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// 计算n!中2的次数
int countPowerOf2(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i *= 2)
    {
        count += n / i;
    }
    return count;
}

// 计算模逆元，用于分数取模
int modInverse(int a, int m = MOD)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int main()
{
    int T;
    cin >> T;
    vector<int> results(T);

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            // 1的因子只有1，概率为1
            results[i] = 1;
            continue;
        }

        // 计算n!中2的次数
        int powerOf2 = countPowerOf2(n);

        // 奇数因子的概率为1/(powerOf2+1)
        int denominator = powerOf2 + 1;
        int probability = (1LL * 1 * modInverse(denominator)) % MOD;

        results[i] = probability;
    }

    // 输出结果
    for (int i = 0; i < T; i++)
    {
        cout << results[i];
        if (i < T - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
