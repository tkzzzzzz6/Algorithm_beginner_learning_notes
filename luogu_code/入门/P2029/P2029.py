import math

h,r = map(int,input().split())
v = 3.14 *r*r*h
bucket_ammount = 20*1e3/v
print(math.ceil(bucket_ammount))