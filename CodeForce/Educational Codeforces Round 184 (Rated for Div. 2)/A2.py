import bisect

t = int(input())
for _ in range(t):
    n, a = map(int, input().split())
    v = list(map(int, input().split()))
    
    idx = bisect.bisect_left(v, a)
    
    # 检查 a 是否在数组中
    has_a = (idx < n and v[idx] == a)
    
    left_count = idx
    if has_a:
        right_count = n - idx - 1  # 不包括 a 本身
    else:
        right_count = n - idx
    
    if left_count > right_count:
        print(a - 1)
    else:
        print(a + 1)