#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// �洢������ַ�����
vector<vector<char>> martix;

// ��ϣ���������ַ�����ֵ�Ǹ��г��ֵĴ���
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;

    // ��ʼ�� n �� m �е��ַ�����
    martix.resize(n, vector<char>(m));

    // ��������ÿ���ַ�
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> martix[i][j];
        }
    }

    // ����ÿһ�У���ÿ�е��ַ�ƴ�ӳ��ַ���
    for (int j = 0; j < m; ++j) {
        string s = "";
        // ���ϵ���ƴ�ӵ� j �е������ַ�
        for (int i = 0; i < n; ++i) {
            s += martix[i][j];
        }
        // ͳ�Ƹ����ַ������ֵĴ���
        mp[s]++;
    }

    // �ҳ����ִ��������У�����ظ�������
    int max_cnt = 0;
    for (auto& [str, cnt] : mp) {
        max_cnt = max(max_cnt, cnt);
    }

    // �������ж���������ȫ��ͬ��
    cout << max_cnt << '\n';

    return 0;
}