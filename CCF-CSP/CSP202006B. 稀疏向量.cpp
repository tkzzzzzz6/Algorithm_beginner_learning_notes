/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 15:50:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 18:44:52
 */

//  可以采用双指针归并
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
#define idx first
#define v second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    long long res = 0;

    vector<PII> A(a), B(b);
    for (int i = 0; i < a; ++i) cin >> A[i].idx >> A[i].v;
    for (int i = 0; i < b; ++i) cin >> B[i].idx >> B[i].v;

    int i = 0, j = 0;
    while (i < a && j < b) {
        if (A[i].idx == B[j].idx) {
            res += 1LL * A[i].v * B[j].v;
            ++i, ++j;
        } else {
            if (A[i].idx < B[j].idx)
                ++i;
            else
                ++j;
        }
    }

    cout << res << '\n';
    return 0;
}
