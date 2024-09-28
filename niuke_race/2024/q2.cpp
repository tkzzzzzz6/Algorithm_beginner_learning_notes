#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        printf("%d", 2 * n);
    }
    else
    {
    if (n > m)
    {
        printf("%d", 2 * m + 1);
    }
    else
    {
        printf("%d", 2 * n + 1);
        }
    }
}