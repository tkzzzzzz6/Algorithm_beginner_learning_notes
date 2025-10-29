#include <iostream>
using namespace std;
using LL = long long;

// 预计算表：table[i] 表示 i! 的最后一个非零数字（去除因子2和5后）
// 例如：0!=1, 1!=1, 2!=2, 3!=6, 4!=24→4, 5!=120→4, 6!=720→4, 7!=5040→8...
const int table[10] = { 1, 1, 2, 6, 4, 4, 4, 8, 4, 6 };

// 预计算表：3^i mod 5 的循环节（周期为4）
// pow3_mod5[i] = 3^i mod 5
// 3^0=1, 3^1=3, 3^2=9→4, 3^3=27→2, 3^4=81→1（循环）
const int pow3_mod5[4] = { 1, 3, 4, 2 };

/**
 * 递归计算 H(n)：n! 去除所有因子2和5后的最后一位数字
 *
 * 算法思想：
 * 1. 将 n! 分解为多个部分的乘积
 * 2. 递归处理 n/5，因为每5个数中会有因子5
 * 3. 使用预计算表加速计算
 */
LL H(LL n) {
    // 递归基：0! = 1
    if (n == 0) {
        return 1;
    }

    // P_n 表示当前层的贡献
    // 如果 n >= 10，则贡献为 6（这是数学推导的结果）
    // 否则贡献为 1
    LL P_n = (n / 10 > 0) ? 6 : 1;

    // 乘以 table[n % 10]：处理最后一位数字的贡献
    P_n = (P_n * table[n % 10]) % 10;

    // 递归处理 n/5：处理更高层的贡献
    return (P_n * H(n / 5)) % 10;
}

int main() {
    LL N;
    cin >> N;

    // 特殊情况：0! = 1, 1! = 1
    if (N < 2) {
        cout << 1 << endl;
        return 0;
    }

    // 步骤1：计算 N! 中因子5的个数 C5
    // 使用 Legendre 公式：floor(N/5) + floor(N/25) + floor(N/125) + ...
    LL C5 = 0;
    LL temp = N;
    while (temp > 0) {
        temp /= 5;
        C5 += temp;
    }

    // 步骤2：计算 H(N)，即去除所有因子2和5后的最后一位
    LL H_N = H(N);

    // 步骤3：计算 H(N) mod 5
    LL H_N_mod5 = H_N % 5;

    // 步骤4：计算 3^C5 mod 5
    // 由于 3^i mod 5 的周期为 4，所以用 C5 % 4 作为索引
    LL pow3 = pow3_mod5[C5 % 4];

    // 步骤5：计算 Z = (H_N mod 5) * (3^C5 mod 5) mod 5
    // 这是核心公式，用于计算最后一个非零数字
    LL Z = (H_N_mod5 * pow3) % 5;

    // 步骤6：根据 Z 的值映射到最终结果
    // 这个映射关系是通过数学推导得出的
    int result;
    if (Z == 0) result = 0;       // Z=0 → 结果=0
    else if (Z == 1) result = 6;  // Z=1 → 结果=6
    else if (Z == 2) result = 2;  // Z=2 → 结果=2
    else if (Z == 3) result = 8;  // Z=3 → 结果=8
    else result = 4;              // Z=4 → 结果=4

    // 输出 N! 的最后一个非零数字
    cout << result << endl;

    return 0;
}