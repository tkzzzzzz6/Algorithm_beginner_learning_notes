#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Element
{
    long long value; // 元素值
    long long count; // 连续数量

    Element(long long v, long long c) : value(v), count(c) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    queue<Element> q;

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            // Type 1: 添加c个值为x的元素
            long long c, x;
            cin >> c >> x;
            q.push(Element(x, c));
        }
        else
        {
            // Type 2: 移除前k个元素并输出和
            long long k;
            cin >> k;

            long long sum = 0;

            while (k > 0 && !q.empty())
            {
                Element &front = q.front();

                if (front.count <= k)
                {
                    // 移除整个块
                    sum += front.value * front.count;
                    k -= front.count;
                    q.pop();
                }
                else
                {
                    // 只移除部分块
                    sum += front.value * k;
                    front.count -= k;
                    k = 0;
                }
            }

            cout << sum << endl;
        }
    }

    return 0;
}