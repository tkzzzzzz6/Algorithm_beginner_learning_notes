#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 2e18; // ����жϱ߽�

// �����ݣ���������
// ���� a^b������������ INF �� -INF
ll quick_pow(ll a, ll b)
{
    // �������
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    if (a == -1)
        return (b % 2 == 0) ? 1 : -1;

    // ���ָ��̫���ҵ�������ֵ >= 2���϶������
    if (b >= 60 && abs(a) >= 2)
        return (a > 0) ? INF : ((b % 2 == 0) ? INF : -INF);

    ll result = 1;
    ll base = a;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            // ���˷����
            if (result > 0 && base > 0 && result > INF / base)
                return INF;
            if (result < 0 && base < 0 && result < INF / base)
                return INF;
            if (result > 0 && base < 0 && result > -INF / base)
                return -INF;
            if (result < 0 && base > 0 && result < -INF / base)
                return -INF;

            result *= base;

            // ������Ƿ񳬳���Χ
            if (abs(result) > INF)
                return result > 0 ? INF : -INF;
        }

        // base = base * base
        if (abs(base) > 1e9) // �������
        {
            if (b > 1)
                return (base > 0) ? INF : ((b % 2 == 0) ? INF : -INF);
        }
        else
        {
            base = base * base;
        }

        b /= 2;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c, d, e, f, g;
        cin >> a >> b >> c >> d >> e >> f >> g;

        ll ad = quick_pow(a, d);
        ll be = quick_pow(b, e);
        ll cf = quick_pow(c, f);

        // ����κ�һ�����������Ƿ����Բ����� g
        if (abs(ad) > INF || abs(be) > INF || abs(cf) > INF)
        {
            cout << "No" << endl;
            continue;
        }

        // ���ӷ����
        ll sum = ad;
        if (sum > INF - be || sum < -INF - be)
        {
            cout << "No" << endl;
            continue;
        }
        sum += be;

        if (sum > INF - cf || sum < -INF - cf)
        {
            cout << "No" << endl;
            continue;
        }
        sum += cf;

        if (sum == g)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}