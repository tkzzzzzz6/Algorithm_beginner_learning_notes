
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(0);
    int n;
    cin >> n;

    cout << ll(n) * pow(2, 20 - 2);//ע��pow��Ӧ�ļ�������double,������õ��ǿ�ѧ������

    return 0;
}