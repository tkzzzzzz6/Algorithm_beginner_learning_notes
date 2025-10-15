n,m,r,k = map(int,input().split())
a = []
def is_prime(num):
    if num <2:
        return False
    for i in range(2,int(num**0.5)+1):
        if num % i == 0:
            return False
    return True


for i in range(1,n+1):
    if is_prime(i) and i%m == r:
        a.append(i)
    if len(a) == k:
        break

if len(a) >= k:
    print(a[k-1])
else:
    print(-1)
