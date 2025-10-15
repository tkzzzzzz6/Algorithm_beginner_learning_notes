a,b,c,d1 = map(str,input().split('-'))
a = int(a)
b = int(b)
c = int(c)

if d1 == 'X':
    d = 10
else:
    d = int(d1)

m = (a*1000+b)*100000+c
s = 0
for i in range(9):
    s += m%10*(9-i)
    s %= 11 
    m //= 10

if s == d:
    print("Right")
else:   
    if s == 10:
        print(f"{a}-{b}-{c}-X")
    else:
        print(f"{a}-{b}-{c}-{s}")

