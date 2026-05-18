/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-18 10:26:26
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-18 10:55:27
 */
/*
 * @acwing app=acwing.cn id=3212 lang=C++
 *
 * 3209. 集合竞价
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
const int N = 5010;

int n;

struct Record {
    int type;
    double p;    // 价格
    ll s;        // 数量
    bool is_del; // 记录是否序号删除
} d[N];

int main() {
    string type;
    n = 0;
    while (cin >> type) {
        if (type == "buy") {
            double p;
            ll s;
            cin >> p >> s;
            d[++n] = {1, p, s, false};
        } else if (type == "sell") {
            double p;
            ll s;
            cin >> p >> s;
            d[++n] = {2, p, s, false};
        } else if (type == "cancel") {
            int line;
            cin >> line;
            d[line].is_del = true;
            d[++n].is_del = true; //cancel 类型的行也需要记录
        }
    }

    // 枚举所有的价格
    double resp;
    ll ress = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i].is_del == false) {
            double p = d[i].p;
            ll s1 = 0, s2 = 0;
            for (int j = 1; j <= n; ++j) {
                if (d[j].is_del == false) {
                    if (d[j].type == 1 && d[j].p >= p)
                        s1 += d[j].s;
                    else if (d[j].type == 2 && d[j].p <= p)
                        s2 += d[j].s;
                }
            }
            ll t = min(s1, s2);
            if (t > ress || (t == ress && p > resp)) {
                resp = p;
                ress = t;
            }
        }
    }

    printf("%.2lf %lld\n", resp, ress);

    return 0;
}
// @acwing code end
