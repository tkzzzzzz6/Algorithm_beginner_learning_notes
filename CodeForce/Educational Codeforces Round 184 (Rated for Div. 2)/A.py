t = int(input())

for _ in range(t):
    n, a = map(int, input().split())
    v = list(map(int, input().split()))

    mids = []
    l = []
    r = []

    for x in v:
        mid = (x + a) // 2
        mids.append(mid)
        if x < a:
            l.append(mid)
        elif x > a:
            r.append(mid)

    mids = sorted(set(mids))
    l.sort()
    r.sort()

    best_b = 0
    best_win = -1

    li = 0
    ri = len(r)

    for b in mids:
        # 左边：mid > b
        while li < len(l) and l[li] <= b:
            li += 1
        win_left = len(l) - li

        # 右边：mid < b
        while ri > 0 and r[ri - 1] >= b:
            ri -= 1
        win_right = ri

        wins = win_left + win_right

        if wins > best_win:
            best_win = wins
            best_b = b

    print(best_b)
