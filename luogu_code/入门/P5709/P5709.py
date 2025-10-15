m,t,s = map(int,input().split())

if s < m*t and t != 0:
    print(int(m-(s/t)))
else:
    print(0)