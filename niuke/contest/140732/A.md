# A. A Bit Common

## 题目描述

Given two integers $n$ and $m$ , among all the sequences containing $n$ non-negative integers less than $2^m$ , you need to count the number of such sequences $A$ that there exists a non-empty subsequence of $A$ in which the bitwise AND of the integers is $1$ .  

Note that a non-empty subsequence of a sequence $A$ is a non-empty sequence that can be obtained by deleting zero or more elements from $A$ and arranging the remaining elements in their original order.  

Since the answer may be very large, output it modulo a positive integer $q$ .  

  
The bitwise AND of non-negative integers $A$ and $B$ , $A\ \texttt{AND}\ B$ is defined as follows:  
- When $A\ \texttt{AND}\ B$ is written in base two, the digit in the $2^d$ 's place ( $d \ge 0$ ) is $1$ if those of $A$ and $B$ are**both** $1$ , and $0$ otherwise.

  
For example, we have $4\ \texttt{AND}\ 6$ = $4$ (in base two: $100\ \texttt{AND}\ 110$ = $100$ ).  

Generally, the bitwise AND of $k$ non-negative integers $p_1, p_2, \ldots, p_k$ is defined as  
$(\ldots((p_1\ \texttt{AND}\ p_2)\ \texttt{AND}\ p_3)\ \texttt{AND}\ \ldots\ \texttt{AND}\ p_k)$   
and we can prove that this value does not depend on the order of $p_1, p_2, \ldots, p_k$ .  
  


## 输入描述

The only line contains three integers $n$ ( $1 \le n \le 5\,000$ ), $m$ ( $1 \le m \le 5\,000$ ) and $q$ ( $1 \le q \le 10^9$ ).  


## 输出描述

Output a line containing an integer, denoting the answer.  


## 样例

### 样例 1
**输入**:
```
2 3 998244353
```

**输出**:
```
17
```

### 样例 2
**输入**:
```
5000 5000 998244353
```

**输出**:
```
2274146
```

