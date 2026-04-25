import sys

def main():
    import sys
    import math

    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    min_a = min(a)
    max_a = max(a)
    # Compute x as ceil((min_a + max_a)/2)
    x = (min_a + max_a +1) //2
    A = x - min_a
    B = max_a -x
    if A <0:
        A=0
    if B <0:
        B=0
    total_operations = max(2*A -1, 2*B) if (A >0 or B >0) else 0
    print(total_operations, x)

if __name__ == "__main__":
    main()
