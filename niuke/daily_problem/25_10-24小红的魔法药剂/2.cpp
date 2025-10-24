#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;  // ҩ����������
    cin >> n;

    // �洢ÿ�ֺ�ɫҩ���Ĺ���۸�
    vector<int> red_cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> red_cost[i];
    }

    ll total_cost = 0;  // ��С�ܻ���

    // ��ÿ��ҩ����������������С�ɱ�
    for (int i = 0; i < n; ++i) {
        // ��ȡ�ϳ��䷽
        pair<int, int> recipe; // �ϳɵ� i ����ɫҩ����Ҫ�����ֺ�ɫҩ�����
        cin >> recipe.first >> recipe.second;

        // �������ֻ�÷�ʽ�ĳɱ�
        int cost_buy_red = red_cost[i]; // ֱ�ӹ����ɫ
        int cost_make_blue = red_cost[recipe.first - 1] + red_cost[recipe.second - 1];  // �ϳ���ɫ

        // ѡ��ɱ��ϵ͵ķ���
        total_cost += min(cost_buy_red, cost_make_blue);
    }

    //���
    cout << total_cost << '\n';

    return 0;
}