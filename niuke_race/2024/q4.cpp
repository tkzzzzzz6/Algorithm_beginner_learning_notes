#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int T;
    cin >> T; // 读取测试用例数量

    while (T--)
    { // 对每个测试用例进行处理
        int n;
        cin >> n; // 读取小朋友数量

        vector<int> a(n);
        int min_star = n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; // 读取每个小朋友手中的星星数量
            min_star = min(min_star, a[i]);
        }

        if (n <= min_star){
            printf("Cool!\n");
        }else{
            printf("%d\n",min_star+1);
        }

    }

    return 0;
}