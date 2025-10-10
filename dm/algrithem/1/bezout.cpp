#include <bits/stdc++.h>
using namespace std;

// �޸�Ϊ�����汾����չŷ������㷨
int extendedGCD(int a, int b, int &s, int &t) {
    int old_s = 1, s_temp = 0;
    int old_t = 0, t_temp = 1;
    
    while (b != 0) {
        int quotient = a / b;
        
        // ����ϵ��
        int new_s = old_s - quotient * s_temp;
        int new_t = old_t - quotient * t_temp;
        
        // ������ֵ
        old_s = s_temp;
        s_temp = new_s;
        
        old_t = t_temp;
        t_temp = new_t;
        
        // �����µ�a��b
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    s = old_s;
    t = old_t;
    return a;
}

int main() {
    // ���IO����
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a = 2009, b = 1394;
    
    int s, t;
    int gcd = extendedGCD(a, b, s, t);
    
    cout << "���Լ����" << gcd << "\n";  // ʹ�û��з�����endl
    cout << a << " * (" << s << ") + " 
         << b << " * (" << t << ") = " << gcd << "\n";
    
    if (a * s + b * t == gcd) {
        cout << "��֤�ɹ���\n";
    }
    
    return 0;
} 