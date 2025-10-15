#include <iostream>
using namespace std;

bool digit_parity(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }
    if (cnt % 2 == 0)
    {
        return false;
    }
}

int main()
{
    int m, k;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k >> k;
        cout << (digit_parity(k - 1) ? "BLACK\n" : "RED\n");
    }
}