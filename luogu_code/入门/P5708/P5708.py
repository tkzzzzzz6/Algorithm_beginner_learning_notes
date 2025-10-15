a, b, c = map(float, input().split())
def calc_s(a, b, c):
    p = (a + b + c) / 2
    s = (p * (p - a) * (p - b) * (p - c)) ** 0.5
    return round(s, 1)
if a + b > c and a + c > b and b + c > a:
    print(calc_s(a, b, c))
else:
    print("These numbers cannot form a triangle.")