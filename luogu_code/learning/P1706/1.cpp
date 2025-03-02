#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    do
    {
        // for (int i = 0; i < n; i++)
        //     printf("%5d ", a[i]);
        // printf("\n");
        // 使用cout打印
        for (int i = 0; i < n; i++)
            cout << setw(5) << a[i] << " ";
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
