#include <iostream>
using namespace std;
using LL = long long;

// Ԥtable[i] ʾ i! һ֣ȥ25
// 磺0!=1, 1!=1, 2!=2, 3!=6, 4!=244, 5!=1204, 6!=7204, 7!=50408...
const int table[10] = { 1, 1, 2, 6, 4, 4, 4, 8, 4, 6 };

// Ԥ3^i mod 5 ѭڣΪ4
// pow3_mod5[i] = 3^i mod 5
// 3^0=1, 3^1=3, 3^2=94, 3^3=272, 3^4=811ѭ
const int pow3_mod5[4] = { 1, 3, 4, 2 };

/**
 * ݹ H(n)n! ȥ25һλ
 *
 * 㷨˼룺
 * 1.  n! ֽΪֵĳ˻
 * 2. ݹ鴦 n/5Ϊÿ5л5
 * 3. ʹԤټ
 */
LL H(LL n) {
    // ݹ0! = 1
    if (n == 0) {
        return 1;
    }

    // P_n ʾǰĹ
    //  n >= 10Ϊ 6ѧƵĽ
    // Ϊ 1
    LL P_n = (n / 10 > 0) ? 6 : 1;

    //  table[n % 10]һλֵĹ
    P_n = (P_n * table[n % 10]) % 10;

    // ݹ鴦 n/5߲Ĺ
    return (P_n * H(n / 5)) % 10;
}

int main() {
    LL N;
    cin >> N;

    // 0! = 1, 1! = 1
    if (N < 2) {
        cout << 1 << endl;
        return 0;
    }

    // 1 N! 5ĸ C5
    // ʹ Legendre ʽfloor(N/5) + floor(N/25) + floor(N/125) + ...
    LL C5 = 0;
    LL temp = N;
    while (temp > 0) {
        temp /= 5;
        C5 += temp;
    }

    // 2 H(N)ȥ25һλ
    LL H_N = H(N);

    // 3 H(N) mod 5
    LL H_N_mod5 = H_N % 5;

    // 4 3^C5 mod 5
    //  3^i mod 5 Ϊ 4 C5 % 4 Ϊ
    LL pow3 = pow3_mod5[C5 % 4];

    // 5 Z = (H_N mod 5) * (3^C5 mod 5) mod 5
    // ǺĹʽڼһ
    LL Z = (H_N_mod5 * pow3) % 5;

    // 6 Z ֵӳ䵽ս
    // ӳϵͨѧƵó
    int result;
    if (Z == 0) result = 0;       // Z=0  =0
    else if (Z == 1) result = 6;  // Z=1  =6
    else if (Z == 2) result = 2;  // Z=2  =2
    else if (Z == 3) result = 8;  // Z=3  =8
    else result = 4;              // Z=4  =4

    //  N! һ
    cout << result << endl;

    return 0;
}
