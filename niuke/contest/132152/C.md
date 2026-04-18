# C. Swap Sorting

## 题目描述

$\hspace{15pt}$ 给定长度为 $n$ 的正整数数组 $a_1, a_2, \dots, a_n$ ，共有 $q$ 次独立询问。每次询问给定一个正整数 $x$ ，请判断在数组**原始状态**下，是否可以通过若干次操作（可以不操作）将数组变为升序：  
$\hspace{23pt}\bullet\,$ 选择两个下标 $i$ 和 $j$ ，满足 $a_i \times a_j \ge x$ ，交换 $a_i$ 和 $a_j$ 。  


## 输入描述

$\hspace{15pt}$ 第一行输入两个整数 $n, q \left(1 \le n,q \le 10^5 \right)$ 。  
$\hspace{15pt}$ 第二行输入 $n$ 个整数，表示数组 $a_1, a_2, \dots, a_n \left(1 \le a_i \le 10^9 \right)$ 。  
$\hspace{15pt}$ 此后 $q$ 行，第 $i$ 行输入一个正整数 $x_i \left(1 \le x_i \le 10^{18} \right)$ 。  
  


## 输出描述

$\hspace{15pt}$ 对于每一次询问，新起一行。如果能通过若干次操作将数组变为升序，输出 $\texttt{Yes}$ ，否则输出 $\texttt{No}$ 。  


## 样例

### 样例 1
**输入**:
```
5 4
1 4 3 10 9
15
35
100
5
```

**输出**:
```
Yes
No
No
Yes
```

