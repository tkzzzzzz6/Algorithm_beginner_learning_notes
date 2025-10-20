#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;  // ģ��

// �������㷨 
// ���ܣ����� a^b % mod
// ԭ�����ö����Ʋ�֣���ָ��b��ʾΪ��������ʽ
// ���磺3^13 = 3^(1101?) = 3^8 �� 3^4 �� 3^1
ll power(ll a, ll b, ll mod) {
    ll result = 1;      // ��ʼ���Ϊ1
    a %= mod;           // �ȶ�aȡģ����ֹ���

    while (b > 0) {     // ��ָ������0ʱ����
        // ���b�����λ�Ƿ�Ϊ1
        if (b & 1) {    // �൱�� if (b % 2 == 1)
            // �����ǰλ��1������Ӧ��a^(2^i)������
            result = result * a % mod;
        }

        // a�Գˣ���a^1���a^2, a^4, a^8, ...
        a = a * a % mod;

        // b����һλ���൱��b����2
        b >>= 1;        // �൱�� b /= 2
    }

    return result;
}

// ģ��Ԫ 
// ���ܣ����� a ��ģ mod �µĳ˷���Ԫ
// ���壺�� a �� x �� 1 (mod p)�����xΪa����Ԫ������a^(-1)
// ԭ�����ݷ���С������pΪ����ʱ��a^(p-1) �� 1 (mod p)
//      ��� a^(p-2) �� a �� 1 (mod p)
//      ���� a^(-1) = a^(p-2) mod p
ll inv(ll a, ll mod) {
    // ���÷���С����a^(-1) = a^(mod-2) mod mod
    return power(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T; 

    // ��������C(n)��ʾ:n��Ԫ�صĺϷ���ջ������
    // ����������C(n) = (2n)! / ((n+1)! �� n!)
    int maxN = 100005;  // ���nֵ��������Ŀ���ݷ�Χ1��??��10^5��
    vector<ll> catalan(maxN);

    // ��ʼ����
    catalan[0] = 1;  // C(0) = 1
    catalan[1] = 1;  // C(1) = 1

    // ���Ƽ��㿨������ 
    // ���ƹ�ʽ��C(n) = C(n-1) �� 2(2n-1) / (n+1)
    // �Ƶ����̣�
    // C(n) = (2n)! / ((n+1)! �� n!)
    // C(n-1) = (2n-2)! / (n! �� (n-1)!)
    // C(n) / C(n-1) = [(2n)! / ((n+1)! �� n!)] / [(2n-2)! / (n! �� (n-1)!)]
    //                = (2n)! �� n! �� (n-1)! / ((n+1)! �� n! �� (2n-2)!)
    //                = (2n)(2n-1)(2n-2)! / ((n+1) �� n �� (n-1)! �� n!)
    //                = (2n)(2n-1) / ((n+1) �� n)
    //                = 2(2n-1) / (n+1)
    // ��ˣ�C(n) = C(n-1) �� 2(2n-1) / (n+1)

    for (int i = 2; i < maxN; i++) {
        // ���� C(i) = C(i-1) �� 2(2i-1) / (i+1)

        // ����1��C(i-1) �� 2(2i-1)
        catalan[i] = catalan[i - 1] * (4 * i - 2) % MOD;

        // ����2������ (i+1)
        // ��ģ�����£����� = ������Ԫ
        // a / b �� a �� b^(-1) (mod p)
        catalan[i] = catalan[i] * inv(i + 1, MOD) % MOD;
    }

    // ����ÿ���������� 
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;

        ll result;

        // ���У�n=1ʱ��A1���ܵ�һ����ջ���޽�
        if (n == 1) {
            result = 0;
        }
        else {
            // �� = C(n) - C(n-1)
            //  C(n)�����кϷ��ĳ�ջ������
            //  C(n-1)��A1��һ����ջ�����������൱��ʣ��n-1��Ԫ�صı�׼���⣩
            //  C(n) - C(n-1)��A1����һ����ջ��������

            result = (catalan[n] - catalan[n - 1] + MOD) % MOD;

            // ��MOD��Ϊ�˷�ֹ���Ϊ����
            // ��ģ�����£�(a - b) % MOD �����Ǹ���
            // ��ȷ������(a - b + MOD) % MOD
        }

        cout << "Case #" << caseNum << ": " << result << '\n';
    }

    return 0;
}