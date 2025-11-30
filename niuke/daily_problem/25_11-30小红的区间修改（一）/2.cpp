#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#define ll long long 
using namespace std;

// 使用lower_bound会先找到比自己小的第一个元素的
// 的下一个元素的迭代器
// 然后再进行比较大小，如果
// 这一个的左边界比上一个区间的右边界要小，或者
// 这一个区间的右边界比右边的左边界要大
// 这两种情况都不会有下一步的进行
// 那么无需更新结果直接输出上一次结果即可

// 这里使用set容器的好处就是可以自动进行排序

// 下一步是检查区间大小加一是否大于之前的结果
// 如果大于的话，更新结果
// 如果小于插入后不更新结果

// 最后输出结果
set<pair<int,int>>vp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vp.clear();

    int q;
    cin>>q;

    // 既然无法改变环境，那么就先适应环境
    int res = 1;
    while (q--)
    {
        int a,b;
        cin>>a>>b;
        // 如果不操作，我甚至可以不插入
        pair<int,int>temp = make_pair(a,b);
        if (vp.empty())
        {
            vp.insert(temp);
            res = 2+b-a;
        }
        else   
        {
            auto it = vp.lower_bound(temp);
            if (it == vp.begin())
            {
                if (b < (*(vp.begin())).first)
                {
                    vp.insert(temp);
                    res = max(b-a+2,res);
                }
            }
            else if (it == vp.end())
            {
                it--;
                if (a > (*it).second)
                {
                    vp.insert(temp);
                    res = max(b-a+2,res);
                }
            }
            else 
            {
                auto it1 = it;
                it--;
                // 检查是否发生重叠
                int right = (*it1).first;
                int left = (*it).second;
                if (b <right&&a >left)
                {
                    vp.insert(temp);
                    res = max(b-a+2,res);
                }
            }
        }

        cout<<res<<'\n';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
