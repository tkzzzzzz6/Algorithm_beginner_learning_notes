#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//水平面的高度h
//小歪的坐标(0,0,0)
//要射的点的坐标假设为(x,y,z)
//由空间中直线的两点式子可得射线的向量表示形式为(x_2 - x_1, y_2 - y_1, z_2 - z_1) = (x - 0, y - 0, z+2*(h - z))

//找两个数的最大公约数
ll gcd2(ll a, ll b) {

    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//找三个数的最大公约数
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
        //若 h 或 z 较大（接近 10 ^ 9），2 * h 可能接近 2e9，int 在极限情况下可能接近越界风险。推荐用 long long（ll）以保证安全。
        //z = z + 2 * (h - z);
        ll z_img = 2 * h - z;
        //确保x,y和z_img和都是正数,这里题目数据都是正数可以不用llabs
        ll g = gcd3(llabs(x), llabs(y), llabs(z_img));

        //这里必须要使用ll,使用int会溢出,有6组用例无法通过
        ll i = x / g;
        ll j = y / g;
        ll k = z_img / g;

        cout << i << ' ' << j << ' ' << k << '\n';
    }
    return 0;
}