#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//ˮƽĸ߶h
//С(0,0,0)
//ҪĵΪ(x,y,z)
//ɿռֱߵʽӿɵߵʾʽΪ(x_2 - x_1, y_2 - y_1, z_2 - z_1) = (x - 0, y - 0, z+2*(h - z))

//Լ
ll gcd2(ll a, ll b) {

    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//Լ
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
        // h  z ϴ󣨽ӽ 10 ^ 92 * h ܽӽ 2e9int ڼ¿ܽӽԽաƼ long longllԱ֤ȫ
        //z = z + 2 * (h - z);
        ll z_img = 2 * h - z;
        //ȷx,yz_imgͶ,ĿݶԲllabs
        ll g = gcd3(llabs(x), llabs(y), llabs(z_img));

        //Ҫʹll,ʹint,6޷ͨ
        ll i = x / g;
        ll j = y / g;
        ll k = z_img / g;

        cout << i << ' ' << j << ' ' << k << '\n';
    }
    return 0;
}
