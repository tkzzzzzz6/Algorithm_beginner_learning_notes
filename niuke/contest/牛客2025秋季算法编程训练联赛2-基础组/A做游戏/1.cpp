#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    // ̰�Ĳ��ԣ�
    // ţţ��ʯͷ(a) �� ţ���ֵļ���(y) -> Ӯ min(a, y) ��
    // ţţ�ļ���(b) �� ţ���ֵĲ�(z)   -> Ӯ min(b, z) ��
    // ţţ�Ĳ�(c)   �� ţ���ֵ�ʯͷ(x) -> Ӯ min(c, x) ��

    ll win_cnt = min(a, y) + min(b, z) + min(c, x);

    cout << win_cnt << endl;

    return 0;
}