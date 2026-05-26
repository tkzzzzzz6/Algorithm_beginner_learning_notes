/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 15:03:10
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 15:47:13
 */
#include <iostream>
#include <vector>

struct Point {
    long long x, y;
};

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Point> A, B;
    for (int i = 0; i < n; ++i) {
        char type;
        Point p;
        cin >> p.x >> p.y >> type;
        if (type == 'A') {
            A.push_back(p);
        } else {
            B.push_back(p);
        }
    }

    while (m--) {
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        int signA = 0, signB = 0;
        bool ok = true;
        for (auto p : A) {
            long long v = t0 + t1 * p.x + t2 * p.y;
            if (v == 0) {
                ok = false;
                break;
            }
            int s = 0;
            (v > 0) ? s = 1 : s = -1;
            if (signA == 0)
                signA = s;
            else {
                if (signA != s) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            for (auto p : B) {
                long long v = t0 + t1 * p.x + t2 * p.y;
                if (v == 0) {
                    ok = false;
                    break;
                }
                int s = 0;
                (v > 0) ? s = 1 : s = -1;
                if (signB == 0) {
                    signB = s;
                } else {
                    if (signB != s) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok && signA != signB) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
