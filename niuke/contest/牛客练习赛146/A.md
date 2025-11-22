## 题目描述$\hspace{15pt}$有 $n$ 台机器排成一排，编号为 $1,2,\dots,n$。

       第 $i$ 台机器上初始有 $a_i$ 枚代币。代币总数在任何时刻均保持不变。

$\hspace{15pt}$我们定义一台机器是合格的，当且仅当它当前的代币数量为偶数；否则为不合格。

  

        定义一次「转移」操作为：

$\hspace{23pt}\bullet\,$从任意一台代币数至少为 $2$ 的机器上取出 $1$ 枚代币，再将其放入任意一台机器（可以是自身，也可以是其他机器）。

  

$\hspace{15pt}$求：经过若干次转移后，**最多**能让多少台机器同时处于合格状态？

## 输入描述:

$\hspace{15pt}$第一行输入一个整数 $n \left(1 \le n \le 2\times 10^5\right)$，表示机器的数量。  
$\hspace{15pt}$第二行输入 $n$ 个整数 $a_1, a_2, \dots, a_n \left(1 \le a_i \le 100\right)$，表示每个机器的代币数量。  

## 输出描述:

$\hspace{15pt}$输出一个整数，表示最多可以有多少个机器是合格的。

示例1

## 输入

[复制](https://ac.nowcoder.com/acm/contest/122727/) 

3
1 2 3

## 输出

[复制](https://ac.nowcoder.com/acm/contest/122727/) 

3

## 说明

$\hspace{15pt}$在这个样例中，最优的转移操作为：  
$\hspace{23pt}\bullet\,$从第三个机器取 $1$ 枚代币放到第一个机器，此时所有机器中的代币数均为 $2$。

示例2

## 输入

[复制](https://ac.nowcoder.com/acm/contest/122727/) 

3
2 2 5

## 输出

[复制](https://ac.nowcoder.com/acm/contest/122727/) 

2