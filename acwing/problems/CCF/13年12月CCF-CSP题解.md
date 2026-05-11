---
title: 13年12月CCF-CSP题解
categories:
  - 算法蒟蒻的成长记录
date: 2026-05-10
tags:
  - CSP
  - 动态规划
  - DFS
  - 组合数学
---

# 1. 出现次数最多的数

给定 $n$ 个正整数，找出它们中出现次数最多的数。

如果这样的数有多个，请输出其中最小的一个。

## 思路 1:哈希

时间复杂度 $O(n)$

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
int s[N];

int main(){
    int n;cin >> n;
    
    while(n--){
        int x;cin >> x;
        s[x]++;
    }

    int res = 0;
    for(int i = 1;i<N;++i){
        if(s[i] > s[res])res = i;
    }

    cout << res << endl;

    return 0;
}
```

## 思路 2:排序 + 双指针

时间复杂度 $O(n \log n)$,不如哈希

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;cin >> n;
    vector<int> s(n);
    
    for(int i =0;i<n;++i){
        cin >> s[i];
    }

    sort(s.begin(),s.end());

    int res = 0,maxlen = 0;
    int i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n && s[i] == s[j])j++;
        if(maxlen < j - i)res = s[i],maxlen = j - i;
        i = j; //手动跳过已经统计的重复元素,这里使用 for循环不要加上++i,不然有元素会跳过,等效于下面的 for 循环
    }

    // for(int i =0;i<n;){
        // ...
    // }

    cout << res << endl;

    return 0;
}
```



---

# 2. ISBN 号码

每一本正式出版的图书都有一个 ISBN 号码与之对应。

ISBN 码包括 9 位数字、1 位识别码和 3 位分隔符，其规定格式如 `x-xxx-xxxxx-x`，其中符号 `-` 是分隔符（键盘上的减号），最后一位是识别码，例如 `0-670-82162-4` 就是一个标准的 ISBN 码。

ISBN 码的首位数字表示书籍的出版语言，例如 `0` 代表英语；第一个分隔符 `-` 之后的三位数字代表出版社，例如 `670` 代表维京出版社；第二个分隔之后的五位数字代表该书在出版社的编号；最后一位为识别码。

识别码的计算方法如下：

首位数字乘以 `1` 加上次位数字乘以 `2` ……以此类推，用所得的结果 $\bmod 11$，所得的余数即为识别码，如果余数为 `10`，则识别码为大写字母 `X`。

例如 ISBN 号码 `0-670-82162-4` 中的识别码 `4` 是这样得到的：对 `067082162` 这 9 个数字，从左至右，分别乘以 $1, 2, \ldots, 9$，再求和，即 $0 \times 1 + 6 \times 2 + \cdots + 2 \times 9 = 158$，然后取 $158 \bmod 11$ 的结果 `4` 作为识别码。

编写程序判断输入的 ISBN 号码中识别码是否正确，如果正确，则仅输出 `Right`；如果错误，则输出是正确的 ISBN 号码。

---

## 思路:模拟

### 如何判断一个 ISBN 编码是否合法?
一个 ISBN 编码由 10 个字符组成,前 9 个字符是数字,最后一个字符可以是数字或者字母 'X'。要判断一个 ISBN 编码是否合法,需要满足以下条件:
$$
\sum_{i=1}^{10} (11-i) \cdot d_i \equiv 0 \pmod{11}
$$
其中 $d_i$ 是 ISBN 编码中第 $i$ 个字符对应的数值,如果是数字则对应其数值,如果是 'X' 则对应 10。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    string s;cin >> s;

    int n = s.size();
    int sum = 0;

    // 注意这里的终止判断是 i + 1 < n 或者写 i < n -1,最后一个数字是用来判断的
    for(int i = 0, j = 1;i+1<n;++i){
        if(s[i] != '-'){
            sum += (s[i] - '0')*j;
            ++j;
        }
    }

    sum %= 11;

    char c = sum + '0';
    if (sum == 10){
        c = 'X';
    }

    if(s.back() == c) puts("Right");
    else{
        s.back() = c;
        cout << s << endl;
    }
    
    return 0;
}
```



# 3. 最大的矩形

![1778381380769.png](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/1778381380769.png)

在横轴上放了 $n$ 个相邻的矩形，每个矩形的宽度是 `1`，而第 $i$（$1 \le i \le n$）个矩形的高度是 $h_i$。

这 $n$ 个矩形构成了一个直方图。找出能放在给定直方图里面积最大的矩形，它的边要与坐标轴平行。

---

## 思路
暴力枚举每个柱子,向左右两边扩展,直到遇到比当前柱子矮的柱子为止,计算矩形面积,更新最大值

时间复杂度:O(n^2)

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
vector<int> h(N);

int main(){
    int n;cin >> n;
    for(int i = 1;i<=n;++i)cin >> h[i];

    int res = 0;
    for(int i = 1;i<=n;++i){
        int left = i,right = i;
        while(left >= 1 && h[left] >= h[i])--left;
        while(right <= n && h[right] >= h[i])++right;
        res = max(res,(right - left - 1)*h[i]);
    }

    cout << res << endl;

    return 0;
}
```


# 4. 有趣的数

我们把一个数称为有趣的，当且仅当：

1. 它的数字只包含 `0, 1, 2, 3`，且这四个数字都出现过至少一次。
2. 所有的 `0` 都出现在所有的 `1` 之前，而所有的 `2` 都出现在所有的 `3` 之前。
3. 最高位数字不为 `0`。

因此，符合我们定义的最小的有趣的数是 `2013`。

除此以外，4 位的有趣的数还有两个：`2031` 和 `2301`。

请计算恰好有 $n$ 位的有趣的数的个数。

由于答案可能非常大，只需要输出答案除以 $10^9 + 7$ 的余数。

---

## 思路:组合数学

根据题意,可以将数字划分成两组
   - 0 和 1 组成的部分,记为 A
   - 2 和 3 组成的部分,记为 B

由于 0 和 1 的顺序固定,2 和 3 的顺序也固定,所以我们只需要考虑如何将 A 和 B 组合在一起即可

设 A 中有 k 个数字,则 B 中有 n-k 个数字,由于最高位不能为 0,所以 A 中至少有一个数字,即 k >= 1,同理 B 中至少有一个数字,即 n-k >= 1,所以 k 的范围是 [1, n-1]

对于每一个 k,我们需要从 n-1 个位置中选择 k 个位置放 A,剩下的位置放 B,所以对于每一个 k,有 $C(n-1, k)$ 种组合方式

再乘以 A 中的数字的排列方式,即 (k-1)! 和 B 中的数字的排列方式,即 (n-k-1)! ,最后将结果对 10^9 + 7 取模即可

> 注意在计算过程中要使用 long long 类型防止溢出,并且注意在乘法过程中要对每一步结果取模,以防止中间结果溢出

```cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1010, MOD = 1e9 + 7;
int C[N][N];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j)
                C[i][j] = 1;
            else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
    }

    ll res = 0;

    for (int k = 2; k <= n - 2; ++k) {
        // % 和 * 同优先级
        res = ( res + (ll)C[n-1][k] * (k - 1) % MOD * (n - k - 1) % MOD) % MOD;
    }

    cout << res << endl;

    return 0;
}
```

# 5. I'm stuck!

给定一个 $R$ 行 $C$ 列的地图，地图的每一个方格可能是 `#`, `+`, `-`, `|`, `.`, `S`, `T` 七个字符中的一个，分别表示如下意思：

- `#`: 任何时候玩家都不能移动到此方格；
- `+`: 当玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非 `#` 方格移动一格；
- `-`: 当玩家到达这一方格后，下一步可以向左右两个方向相邻的一个非 `#` 方格移动一格；
- `|`: 当玩家到达这一方格后，下一步可以向上下两个方向相邻的一个非 `#` 方格移动一格；
- `.`: 当玩家到达这一方格后，下一步只能向下移动一格。如果下面相邻的方格为 `#`，则玩家不能再移动；
- `S`: 玩家的初始位置，地图中只会有一个初始位置。玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非 `#` 方格移动一格；
- `T`: 玩家的目标位置，地图中只会有一个目标位置。玩家到达这一方格后，可以选择完成任务，也可以选择不完成任务继续移动。如果继续移动下一步可以向上下左右四个方向相邻的任意一个非 `#` 方格移动一格。

此外，玩家不能移动出地图。

请找出满足下面两个性质的方格个数：

1. 玩家可以从初始位置移动到此方格；
2. 玩家不可以从此方格移动到目标位置。

## 思路:模拟,dfs两次

先把每种字符对应的移动规则整理清楚，后面写 BFS / DFS 会更方便判断。

| 字符        | 移动规则           | 速记                 |
| ----------- | ------------------ | -------------------- |
| `#`         | 无法移动           | 墙，不能走           |
| `+` `S` `T` | 可以向四个方向移动 | 四个方向都能走       |
| `-`         | 只能左右移动       | 横向通道，只能左、右 |
| `\|`        | 只能上下移动       | 纵向通道，只能上、下 |
| `.`         | 只能向下移动       | 单向通道，只能向下   |


可以采用两次 dfs 来解决这个问题：
 - 第一次 dfs 遍历: 从起点 S 出发，按照地图上每个字符对应的移动规则进行遍历，标记所有可以到达的点。
 - 第二次 dfs 遍历: 从终点 T 出发，按照地图上每个字符对应的移动规则进行遍历，标记所有可以到达的点。

最后统计满足条件的点的数量：即在第一次 dfs 中被标记为可达，但在第二次 dfs 中未被标记为可达的点的数量。

遍历顺序:上右下左(逆时针)

> notice
> 
> 在第二次 dfs 中，我们是从 T 出发，反向遍历地图，按照相反的移动规则进行遍历。
> 
> 例如，如果当前点是 `.`，我们在第二次 dfs 中只能向上移动。
> 
> 这里有一个技巧,第二次 dfs 的 check 函数中 k 的值可以通过 i ^ 2 来得到,因为上下左右的 k 分别是 0,1,2,3,所以 k ^ 2 的结果分别是 2,3,0,1,正好是相反的方向


```cpp
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 55;
char g[N][N];
bool st1[N][N], st2[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool check(int x, int y, int k) {
    char c = g[x][y];
    if (c == '+' || c == 'T' || c == 'S')
        return true;
    if (c == '|' && k % 2 == 0)
        return true;
    if (c == '-' && k % 2 == 1)
        return true;
    if (c == '.' && k == 2)
        return true;
    return false;
}

// 从初始位置 S 可以移动到此方格
void dfs1(int x, int y) {
    st1[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#')
            continue;
        if (st1[a][b])
            continue;
        if (check(x, y, i))
            dfs1(a, b);
    }
}

// 从目标位置 T 不可以移动到的位置->反推
void dfs2(int x, int y) {
    st2[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#')
            continue;
        if (st2[a][b])
            continue;
        if (check(a, b, i ^ 2))
            dfs2(a, b);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> g[i];

    int tx, ty;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'S')
                dfs1(i, j);
            else if (g[i][j] == 'T') {
                tx = i, ty = j;
                dfs2(i, j);
            }
        }
    }

    if (!st1[tx][ty])
        puts("I'm stuck!");
    else {
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (st1[i][j] && !st2[i][j])
                    res++;

        cout << res << endl;
    }

    return 0;
}
```
