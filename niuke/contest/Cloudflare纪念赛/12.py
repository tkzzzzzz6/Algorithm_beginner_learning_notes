import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    if n&1 == 1:
        print(-1)
        return

    a = str(input())
    b = str(input())

    count = {}
    result = []

    for i in range(n):
        char_a = a[i]
        char_b = b[i]

        if char_a == char_b:
            #两个字符相同，必须选择
            result.append(char_a)
            count[char_a] = count.get(char_a,0) + 1
        else:
            #优先选择当前出现次数是奇数的字符,配成偶数
            if count.get(char_a,0) %2 == 1:
                result.append(char_a)
                count[char_a] += 1
            elif count.get(char_b,0) %2 == 1:
                result.append(char_b)
                count[char_b] = count.get(char_b,0) + 1
            else:
                # 都是偶数,随便选一个
                result.append(char_a)
                count[char_a] = count.get(char_a,0) + 1
    for c,cnt in count.items():
        if cnt % 2 == 1:
            print(-1)
            return

    print("".join(result))

if __name__ == "__main__":

    solve()