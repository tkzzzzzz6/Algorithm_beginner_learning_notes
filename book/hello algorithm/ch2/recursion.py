'''
Author: tkzzzzzz6
Date: 2026-03-21 00:39:43
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-21 01:05:19
'''
def recur(n:int)->int:
    if n <= 1:
        return n
    return n + recur(n-1)

def tail_recur(n,res):
    # 尾递归我感觉就是输出的结果放在了递归函数的参数中,不断的更新
    if n == 0:
        return res
    
    tail_recur(n-1,res+n)

def fib(n:int)->int:
    # 终止条件
    if n == 1:
        return 0
    elif n == 2:
        return 1
    
    ans = fib(n-1) + fib(n-2)

    return ans

def for_loop_recur(n:int)->int:
    # 使用迭代模拟递归1 + 2 + 3 + ... n
    stack = []
    res = 0
    # 递
    for i in range(n,0,-1):
        stack.append(i)
    # 归
    while stack:
        res += stack.pop()

    return res

def main():
    print(recur(5))


if __name__ == "__main__":
    main()
