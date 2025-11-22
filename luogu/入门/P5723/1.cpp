#include <iostream>
#include <vector>

using namespace std;

void PrimeList(vector<int> &Prime, vector<bool> &isPrime, int n)
{
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            Prime.push_back(i);
            for (int j = i * 2; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int L, cnt = 0;
    cin >> L;
    vector<int> Prime;
    vector<bool> isPrime;
    PrimeList(Prime, isPrime, L); // Precompute primes up to L
    for (int i = 0; i < Prime.size() && L > 0; i++) {
        if (Prime[i] <= L) {
            L -= Prime[i];
            cout << Prime[i] << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
