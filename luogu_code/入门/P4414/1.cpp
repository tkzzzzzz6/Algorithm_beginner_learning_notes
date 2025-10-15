#include <bits/stdc++.h>

using namespace std;


    int main()
    {
        int temp = 0;
        vector<int> a(3);
        char letter;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < 3; i++)
        {
            cin >> letter;
            cout << (letter == 'A' ? a[0] : (letter == 'B' ? a[1] : a[2])) << " ";
        }

        return 0;
    }

