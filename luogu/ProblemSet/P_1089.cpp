/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 14:49:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 15:09:58
 */
#include <iostream>

using namespace std;
int saved = 0;
int current = 0;

int main() {
    for (int i = 1; i <= 12; ++i) {
        int x;
        cin >> x;
        current += 300; // 获得当前月的凌华强
        current -= x;   // 减去本月开支
        if (current < 0) {
            cout << -1 * i;
            return 0;
        }
        saved += (current / 100) * 100;
        current -= (current / 100) * 100;
    }

    cout << static_cast<int>(current + saved * 1.2);
    return 0;
}
