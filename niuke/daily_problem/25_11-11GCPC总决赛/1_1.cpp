#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false); // 提高cin/cout效率
    cin.tie(nullptr);

    int n;
    cin >> n; // 读取牌的数量
    vector<int> a(n); // dark选手的牌
    vector<int> b(n); // yxl选手的牌

    // 读取dark的牌
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 读取yxl的牌
    for (int i = 0; i < n; i++)
        cin >> b[i];

    // p为下标排列，表示yxl手牌的出牌序列
    vector<int> p(n, 0);
    iota(p.begin(), p.end(), 0); // 初始化为[0,1,...,n-1]

    ll win = 0LL;  // dark胜场计数
    ll lose = 0LL; // dark负场计数
    ll draw = 0LL; // 平场计数

    // 枚举yxl所有出牌排列（n!）
    do
    {
        int dark = 0; // 当前排列下dark的胜的回合数
        int yxl = 0;  // 当前排列下yxl的胜的回合数
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[p[i]])
                dark++; // dark这一回合胜
            else if (a[i] < b[p[i]])
                yxl++; // yxl这一回合胜
            // 相等则本回合平局，不计入任何一方
        }
        if (dark > yxl)
            win++;  // dark总得分多，算一场胜
        else if (dark < yxl)
            lose++; // yxl总得分多，算一场负
        else
            draw++; // 平局
    } while (next_permutation(p.begin(), p.end()));

    // 输出胜、负、平的场数
    cout << win << " " << lose << " " << draw << endl;
}
