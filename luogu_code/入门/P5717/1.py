a,b,c = map(int,input().split())
a,b,c = sorted([a,b,c])


if a+b>c:
    if a**2 + b**2 == c**2:
        print("Right triangle")
    elif a**2 + b**2 > c**2:
        print("Acute triangle")
    elif a**2 + b**2 < c**2:
        print("Obtuse triangle")
    if a == b or b == c or a == c:
        print("Isosceles triangle")
    if a==b==c:
        print("Equilateral triangle")
else:
    print("Not triangle")


    

