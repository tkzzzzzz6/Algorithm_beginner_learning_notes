---
title: 第三次CCF计算机软件能力认证题解(1-3)
categories:
  - 算法蒟蒻的成长记录
date: 2026-05-14
tags:
  - CSP
  - 模拟
  - 数组哈希
---

# 1. 门禁系统

## 问题描述

图书馆需要记录读者到访情况。每位读者有唯一编号，统计每条记录中该读者编号是第几次出现。

### 输入

- 第一行：整数 $n$（记录条数）
- 第二行：$n$ 个整数（每位读者的编号）

### 输出

输出 $n$ 个整数，表示每条记录中该读者是第几次出现。

### 约束

- $1 \le n \le 1000$
- 读者编号：不超过 $n$ 的正整数

### 样例

输入：

```
5
1 2 1 1 3
```

输出：

```
1 1 2 3 1
```

## 思路:数组哈希

使用数组哈希计数：遍历每条记录，每当看到某个读者编号，就把对应位置的计数加 1，输出当前计数即可。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int a[N];  // a[i] 表示读者编号 i 的出现次数，

int main(){
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        a[x]++;           // 该读者出现次数加 1
        cout << a[x] << ' ';
    }
    return 0;
}
```

# 2. Z 字形扫描

## 题目描述

![1778752499404.png](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/1778752499404.png)

按照上面图片的的路径输出矩阵中的元素

# 思路 1:逐斜行输出

这里的 i = 行索引 + 列索引,索引从 1 开始,

- i为奇数从右上到左下
- i 为偶数从左下到右上

为了保证所有枚举的方式是统一的,可以对矩阵进行拓展,拓展,最后遍历的范围为图中紫色和绿色部分,上三角

![1778828132936.png](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/1778828132936.png)

### 代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int g[2*N][2*N];

int main(){
    int n;cin >> n;
    for(int i = 1;i<=n;++i)
        for(int j =1;j<=n;++j)
            scanf("%d",&g[i][j]);

    for(int i = 2;i<=2*n;++i)
    {
        if(i % 2 == 0){ //奇数行开始
            // 左下到右上
            for(int j = i-1;j>=1;--j){
                if(j >= 1 && j <= n && i - j >= 1 && i - j <=n)
                    printf("%d ",g[j][i-j]);
            }
        }else{
            // 右上到左下
            for(int j = 1;j<=i-1;++j){
                if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
                    printf("%d ", g[j][i - j]);
            }
        }
    }

    return 0;
}
```

### 思路 2:偏移量+模拟

这里采用的是提前枚举,不符合要求再换枚举方向的方法

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;
int g[N][N];
int dx[4] = {0, 1, 1, -1}, dy[4] = {1, -1, 0, 1}, dr = 0; //设置偏移量

int main() {
    int n;
    cin >> n;
    // 记录矩阵元素
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &g[i][j]);

    printf("%d ", g[1][1]);
    int x = 1, y = 2;
    for (int i = 1; i <= n * (n * 2); ++i) {
        if (x <= n && y <= n && x >= 1 && y >= 1)
            printf("%d ", g[x][y]);

        int l = x + dx[dr], r = y + dy[dr];
        // 当下一个枚举值是 0,2 类型的偏移或者超出范围的时候,调整枚举方向
        if (dr == 0 || dr == 2 || l > n || l < 1 && r > n || r < 1) {
            dr = (dr + 1) % 4;
            l = x + dx[dr], r = y + dy[dr];
        }

        x = l, y = r;
    }

    return 0;
}
```

# 3.集合竞价

## 题目描述

给定若干条开盘前订单（`buy p s`、`sell p s`、`cancel i`），选择一个开盘价 p0 使得成交量 min(买单(≥p0)总量, 卖单(≤p0)总量) 最大；若并列选最高价。

## 思路:暴力枚举
- 时间复杂度:$O(n^2)$
- 空间复杂度:$O(n)$

定义结构体记录订单类型、价格、数量以及是否被删除。对于每一个订单的价格，枚举作为开盘价，计算满足条件的买单和卖单数量，更新最大成交量和对应的开盘价。

```cpp
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
const int N = 5010;

int n;

struct Record {
    int type;
    double p;    // 价格
    ll s;        // 数量
    bool is_del; // 记录是否序号删除
} d[N];

int main() {
    string type;
    n = 0;
    while (cin >> type) {
        if (type == "buy") {
            double p;
            ll s;
            cin >> p >> s;
            d[++n] = {1, p, s, false};
        } else if (type == "sell") {
            double p;
            ll s;
            cin >> p >> s;
            d[++n] = {2, p, s, false};
        } else if (type == "cancel") {
            int line;
            cin >> line;
            d[line].is_del = true;
            d[++n].is_del = true; //cancel 类型的行也需要记录
        }
    }

    // 枚举所有的价格
    double resp;
    ll ress = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i].is_del == false) {
            double p = d[i].p;
            ll s1 = 0, s2 = 0;
            for (int j = 1; j <= n; ++j) {
                if (d[j].is_del == false) {
                    if (d[j].type == 1 && d[j].p >= p)
                        s1 += d[j].s;
                    else if (d[j].type == 2 && d[j].p <= p)
                        s2 += d[j].s;
                }
            }
            ll t = min(s1, s2);
            if (t > ress || (t == ress && p > resp)) {
                resp = p;
                ress = t;
            }
        }
    }

    printf("%.2lf %lld\n", resp, ress);

    return 0;
}
```
