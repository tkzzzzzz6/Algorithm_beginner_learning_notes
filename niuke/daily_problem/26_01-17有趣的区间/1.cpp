#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long len = 0;
    long long ans = n*(n+1)/2;
    // total = n*(n+1)/2
    for(long long i = 0;i<n;++i)
    {
        long long a;
        cin >> a;
        if((a & 1) != 1)len++;
        else{
            ans -= len*(len+1)/2;
            len = 0;
        }
    }
    ans -= len*(len+1)/2;
    cout << ans << '\n';
}
// 64 位输出请用 printf("%lld")
