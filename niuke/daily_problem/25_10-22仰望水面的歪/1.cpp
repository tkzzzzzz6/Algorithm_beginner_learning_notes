
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//ˮƽ��ĸ߶�h
//С�������(0,0,0)
//Ҫ��ĵ���������Ϊ(x,y,z)
//�ɿռ���ֱ�ߵ�����ʽ�ӿɵ����ߵ�������ʾ��ʽΪ(x_2 - x_1, y_2 - y_1, z_2 - z_1) = (x - 0, y - 0, z+2*(h - z))

//�������������Լ��
ll gcd2(ll a, ll b) {

    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//�������������Լ��
ll gcd3(ll x, ll y, ll z) {
    return gcd2(gcd2(x, y), z);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, h;
    cin >> n >> h;
    while (n--) {
        ll x, y, z;
        cin >> x >> y >> z;
        //(x - 0, y - 0, z + 2 * (h - z))
        //�� h �� z �ϴ󣨽ӽ� 10 ^ 9����2 * h ���ܽӽ� 2e9��int �ڼ�������¿��ܽӽ�Խ����ա��Ƽ��� long long��ll���Ա�֤��ȫ��
        //z = z + 2 * (h - z);
        ll z_img = 2 * h - z;
        //ȷ��x,y��z_img�Ͷ�������,������Ŀ���ݶ����������Բ���llabs
        ll g = gcd3(llabs(x), llabs(y), llabs(z_img));

        ll i = x / g;
        ll j = y / g;
        ll k = z_img / g;


        cout << i << ' ' << j << ' ' << k << '\n';

    }

    return 0;
}