/*
 * 埃拉托斯特尼筛法 (Sieve of Eratosthenes)
 * 用途：快速找出一定范围内的所有素数
 * 时间复杂度：O(n log log n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

// 基础埃氏筛
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// 线性筛（欧拉筛）- 更快的筛法
vector<int> linearSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }

        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }

    return primes;
}

// 区间筛（用于筛选大区间[L, R]的素数）
vector<long long> segmentedSieve(long long L, long long R) {
    long long sqrtR = sqrt(R);
    vector<int> basePrimes = sieveOfEratosthenes(sqrtR);

    vector<bool> isPrime(R - L + 1, true);

    for (int p : basePrimes) {
        long long start = max(p * p, (L + p - 1) / p * p);
        for (long long j = start; j <= R; j += p) {
            isPrime[j - L] = false;
        }
    }

    vector<long long> primes;
    for (long long i = max(2LL, L); i <= R; i++) {
        if (isPrime[i - L]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// 判断单个数是否为素数（试除法）
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Miller-Rabin素性测试（概率算法，适用于大数）
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return result;
}

bool millerRabin(long long n, long long a) {
    if (n % a == 0) return false;
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    long long x = modPow(a, d, n);
    if (x == 1 || x == n - 1) return true;

    for (int i = 0; i < r - 1; i++) {
        x = (__int128)x * x % n;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrimeMR(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    vector<long long> witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (long long a : witnesses) {
        if (n == a) return true;
        if (!millerRabin(n, a)) return false;
    }
    return true;
}

// 质因数分解
vector<pair<long long, int>> primeFactorization(long long n) {
    vector<pair<long long, int>> factors;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }

    if (n > 1) {
        factors.push_back({n, 1});
    }

    return factors;
}

// 使用示例
int main() {
    int n = 100;

    // 埃氏筛
    vector<int> primes = sieveOfEratosthenes(n);
    cout << "Primes up to " << n << ": ";
    for (int p : primes) {
        cout << p << " ";
    }
    cout << "\nTotal: " << primes.size() << endl;

    // 线性筛
    vector<int> primes2 = linearSieve(n);
    cout << "\nLinear sieve count: " << primes2.size() << endl;

    // 判断素数
    long long num = 1000000007;
    cout << "\nIs " << num << " prime? " << (isPrimeMR(num) ? "Yes" : "No") << endl;

    // 质因数分解
    long long num2 = 12345;
    cout << "\nPrime factorization of " << num2 << ":" << endl;
    auto factors = primeFactorization(num2);
    for (auto [p, cnt] : factors) {
        cout << p << "^" << cnt << " ";
    }
    cout << endl;

    return 0;
}
