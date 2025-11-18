import sys, math

def solve():
    j = int(input())
    i = 1
    while i<=j:
        print(i, end=" ")
        i += 1
        if i<=j:
            print(j,end=" ")
            j -= 1

if __name__ == "__main__":
    solve()