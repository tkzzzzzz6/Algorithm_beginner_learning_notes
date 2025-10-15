m,h = map(float,input().split())

BMI = m / h ** 2

if BMI < 18.5:
    print("Underweight")
elif BMI < 24:
    print("Normal")
else:
    print(f"{BMI:6g}")
    print("Overweight")