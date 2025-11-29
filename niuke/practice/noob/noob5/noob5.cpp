//
//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    ios::sync_with_stdio(false), cin.tie(0);
//
//    int a;
//    ll b; 
//    double c; char d;
//    string e;
//    
//    cin >> a >> b >> c >> d >> e;
//    cout << a << '\n' << b << '\n' << fixed << 
//       setprecision(1) <<  c << '\n' << d << '\n' << e << '\n';
//    cout.flush();
//
//}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(1);

    int a;
    ll b;
    double c; char d;
    string e;

    cin >> a >> b >> c >> d >> e;
    cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n';
    cout.unsetf(ios::fixed);
    cout.flush();

}