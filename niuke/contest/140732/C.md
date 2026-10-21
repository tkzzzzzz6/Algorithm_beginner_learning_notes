# C. Sum of Suffix Sums

## 题目描述

Given an array which is initially empty, you need to perform $q$ operations:  
- Given two non-negative integers $t$ and $v$ , take out the element from the end of the array for $t$ times and then append $v$ to the end of the array. It is guaranteed that $t$ does not exceed the length of the array before this operation.

  
After each operation, let $a_1, a_2, \ldots, a_n$ be the current array, find the**sum**of $s_1, s_2, \ldots, s_n$ , where $s_i = a_i + a_{i+1} + \ldots + a_n$ is the sum of the suffix starting from position $i$ .  

Since the answers may be very large, output them modulo $1\,000\,000\,007$ .  


## 输入描述

The first line contains an integer $q$ ( $1 \le q \le 5 \times 10^5$ ), denoting the number of operations.  

Each of the following $q$ lines contains two non-negative integers $t$ and $v$ ( $0 \le v \le 10^9$ ), describing an operation, where $t$ does not exceed the length of the array before this operation.  


## 输出描述

Output $q$ lines, each of which contains an integer, denoting the answer.  


## 样例

### 样例 1
**输入**:
```
5
0 1
0 2
1 3
0 6
2 100000
```

**输出**:
```
1
5
7
25
200001
```

**说明**:  

After the first operation, the current array is $[1]$ , the suffix sum array is $[1]$ , and the sum of the suffix sums is $1$ .  
After the second operation, the current array is $[1,2]$ , the suffix sum array is $[3,2]$ , and the sum of the suffix sums is $5$ .  
After the third operation, the current array is $[1,3]$ , the suffix sum array is $[4,3]$ , and the sum of the suffix sums is $7$ .  
After the fourth operation, the current array is $[1,3,6]$ , the suffix sum array is $[10,9,6]$ , and the sum of the suffix sums is $25$ .  
After the fifth operation, the current array is $[1,100\,000]$ , the suffix sum array is $[100\,001,100\,000]$ , and the sum of the suffix sums is $200\,001$ .  


### 样例 2
**输入**:
```
1
0 1000000000
```

**输出**:
```
1000000000
```

