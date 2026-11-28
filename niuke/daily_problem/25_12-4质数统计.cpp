#include<iostream>
#define il inline
using namespace std;

#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;

const ll N = 10000006;
int primes[N],j,s[N+1];  
bool isPrime[N+1];        

void eulerSieve()
{
    for(ll i = 2;i<=N;++i)
    {
        if(!isPrime[i])
        {
            primes[++j] = i;
            s[i]++;
        }
        for(ll q = 1;q<=j && primes[q] * i <= N;++q) 
        {
            isPrime[primes[q]*i] = 1;
            if(!(i%primes[q]))
            {
                break;
            }
        }
    }
    isPrime[1] = 1;
    for(ll i = 2;i<=N;++i)
    {
        s[i] += s[i-1];
    }
}


il void solve(){
    int l,r;
    cin >> l >> r;
    cout << s[r] - s[l-1] << "\n";
}

int main()
{
    fastio
    
    eulerSieve();  // 调用筛法初始化
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
