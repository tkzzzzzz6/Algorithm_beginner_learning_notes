<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200020;  // 定义数组最大长度

#define ll long long

int main()
{
    // 关闭输入输出流同步，加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;  // 测试用例数量
    cin >> T;
    while(T--){
        int n, k, i, a[MAXN], l, r, longest = 0;
        cin >> n >> k;  // n: 人数, k: 能力值差的最大值
        
        // 读入每个人的能力值
        for (int i = 0; i < n;++i)
            cin >> a[i];
        
        // 对能力值进行排序，方便使用双指针
        sort(a, a + n);
        
        // 双指针/滑动窗口：找满足条件的最长区间
        // l 是左指针，r 是右指针
        for (l = 0, r = 0; l < n; l++){
            // 右指针尽可能向右扩展，直到不满足条件
            // 条件：区间内最大值和最小值的差不超过 k
            // 因为数组已排序，所以 a[r] - a[l] 就是区间的最大差值
            while(r < n && a[r] - a[l] <= k)
                r++;
            
            // 更新最长区间的长度
            // r - l 是以 l 为左端点时，满足条件的最长区间长度
            longest = max(longest, r - l);
        }
        
        // 输出最长区间的长度，即最多可以组队的人数
        cout << longest << '\n';
    }

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200020;  // 定义数组最大长度

#define ll long long

int main()
{
    // 关闭输入输出流同步，加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;  // 测试用例数量
    cin >> T;
    while(T--){
        int n, k, i, a[MAXN], l, r, longest = 0;
        cin >> n >> k;  // n: 人数, k: 能力值差的最大值
        
        // 读入每个人的能力值
        for (int i = 0; i < n;++i)
            cin >> a[i];
        
        // 对能力值进行排序，方便使用双指针
        sort(a, a + n);
        
        // 双指针/滑动窗口：找满足条件的最长区间
        // l 是左指针，r 是右指针
        for (l = 0, r = 0; l < n; l++){
            // 右指针尽可能向右扩展，直到不满足条件
            // 条件：区间内最大值和最小值的差不超过 k
            // 因为数组已排序，所以 a[r] - a[l] 就是区间的最大差值
            while(r < n && a[r] - a[l] <= k)
                r++;
            
            // 更新最长区间的长度
            // r - l 是以 l 为左端点时，满足条件的最长区间长度
            longest = max(longest, r - l);
        }
        
        // 输出最长区间的长度，即最多可以组队的人数
        cout << longest << '\n';
    }

    return 0;
>>>>>>> 6948676579abca6ba4f3824e53edf9bbb7e1b238
}