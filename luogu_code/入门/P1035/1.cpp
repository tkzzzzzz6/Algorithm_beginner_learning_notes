#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 调和级数的近似公式 S(n) ~= ln(n) + 0.5772
    // 调和级数是发散的，所以需要找到一个足够大的n使得S(n) > k
    // for(int i = 1; i < 1000000; i++){
    //     if(log(i) + 0.5772 >= k){
    //         cout << i;
    //         break;
    //     }
    // }
    double k;
    cin >> k;
    double sum = 0;
    for (int i = 1; i < 1000000; i++)
    {
        sum += 1.0 / i;
        if (sum > k)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
