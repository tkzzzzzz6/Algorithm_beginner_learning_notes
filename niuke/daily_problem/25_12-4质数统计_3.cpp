#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 10000006;

// ==================== 函数命名建议 ====================
// 1. 使用筛法名称作为前缀：
//    - eulerSieve() / euler_sieve()      // 欧拉筛
//    - eratosthenesSieve() / eratosthenes_sieve()  // 埃拉托斯特尼筛
//    - linearSieve() / linear_sieve()    // 线性筛（欧拉筛的别名）
//
// 2. 使用功能描述：
//    - sievePrimes() / sieve_primes()    // 筛质数
//    - generatePrimes() / generate_primes()  // 生成质数
//    - getPrimes() / get_primes()        // 获取质数
//
// 3. 组合命名（推荐）：
//    - eulerSievePrimes() / euler_sieve_primes()
//    - eratosthenesSievePrimes() / eratosthenes_sieve_primes()

// ==================== 埃拉托斯特尼筛法（欧式筛）====================
// 思想：
// 1. 从2开始，将所有质数的倍数标记为合数
// 2. 对于每个质数p，标记 p, 2p, 3p, 4p, ... 为合数
// 3. 时间复杂度：O(n log log n)
// 4. 空间复杂度：O(n)
// 5. 缺点：每个合数可能被标记多次（如6会被2和3各标记一次）

vector<int> eratosthenesSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    
    isPrime[0] = isPrime[1] = false;  // 0和1不是质数
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);  // i是质数，加入结果
            
            // 标记i的所有倍数为合数
            // 优化：从i*i开始，因为i*(i-1)之前的已经被更小的质数标记过了
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return primes;
}

// 另一种实现：只返回标记数组，不返回质数列表
void eratosthenesSieveMark(vector<bool>& isPrime, int n) {
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {  // 只需遍历到sqrt(n)
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// ==================== 欧拉筛（线性筛）====================
// 思想：
// 1. 每个合数只被它的最小质因数筛掉一次
// 2. 对于每个数i，用已知的质数primes[j]去筛 i * primes[j]
// 3. 关键：当 i % primes[j] == 0 时停止，保证每个合数只被最小质因数筛一次
// 4. 时间复杂度：O(n) - 线性时间复杂度
// 5. 空间复杂度：O(n)
// 6. 优点：每个合数只被标记一次，效率更高

vector<int> eulerSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        // 如果i是质数，加入质数列表
        if (isPrime[i]) {
            primes.push_back(i);
        }
        
        // 用已知的质数去筛 i * primes[j]
        for (int j = 0; j < primes.size() && primes[j] * i <= n; j++) {
            isPrime[primes[j] * i] = false;  // 标记为合数
            
            // 关键优化：当i能被primes[j]整除时停止
            // 这样可以保证每个合数只被它的最小质因数筛一次
            // 例如：i=4, primes[j]=2时，4*2=8被筛掉，此时停止
            //       如果继续，4*3=12会被筛掉，但12应该被2筛掉（因为12=2*6）
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    
    return primes;
}

// 另一种实现：返回标记数组和质数列表
void eulerSieveMark(vector<bool>& isPrime, vector<int>& primes, int n) {
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        
        for (int j = 0; j < primes.size() && primes[j] * i <= n; j++) {
            isPrime[primes[j] * i] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

// ==================== 使用示例 ====================
int main() {
    int n = 100;
    
    cout << "=== 埃拉托斯特尼筛法 ===" << endl;
    vector<int> primes1 = eratosthenesSieve(n);
    cout << "质数数量: " << primes1.size() << endl;
    cout << "前10个质数: ";
    for (int i = 0; i < min(10, (int)primes1.size()); i++) {
        cout << primes1[i] << " ";
    }
    cout << endl;
    
    cout << "\n=== 欧拉筛（线性筛）===" << endl;
    vector<int> primes2 = eulerSieve(n);
    cout << "质数数量: " << primes2.size() << endl;
    cout << "前10个质数: ";
    for (int i = 0; i < min(10, (int)primes2.size()); i++) {
        cout << primes2[i] << " ";
    }
    cout << endl;
    
    // 验证两种方法结果一致
    cout << "\n=== 验证结果一致性 ===" << endl;
    if (primes1 == primes2) {
        cout << "✓ 两种筛法结果一致" << endl;
    } else {
        cout << "✗ 结果不一致" << endl;
    }
    
    return 0;
}
