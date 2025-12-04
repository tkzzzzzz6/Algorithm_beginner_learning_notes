#include<iostream>
#include<vector>
#define il inline
using namespace std;

#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;

const ll N = 10000006;
vector<int> primes;
vector<int> s(N+1);
vector<bool> isPrime(N+1,true);        

void eulerSieve()
{
    primes.reserve(N);        // 预分配空间，提高效率（可选优化）
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2;i<=N;++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            s[i]++;
        }
        for(ll q = 0;q<primes.size() && primes[q] * i <= N;++q)  // 从0开始，因为vector索引从0开始 
        {
            isPrime[primes[q]*i] = false; // 标记为合数
            if(i%primes[q] == 0)
            {
                break;
            }
        }
    }
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
