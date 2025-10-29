#include <iostream>
using namespace std;
long long f(long long n)
{
    if (n < 20180001)
        return n + 2017;
    return f(f(n - 2018));
}
int main()
{
    long long n;
    cin >> n;
    if (n >= 20182017)
        cout << 20182017;
    else
        cout << f(n) << endl;
    return 0;
}   