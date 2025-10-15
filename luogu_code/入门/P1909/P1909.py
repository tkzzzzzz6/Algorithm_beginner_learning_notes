n = int(input())

package = []
for _ in range(3):
    pencils, price = map(int, input().split())
    package.append((pencils, price))

min_cost = float('inf')
for pencils, price in package:
    num_packages = (n + pencils - 1) // pencils
    cost = num_packages * price
    min_cost = min(min_cost, cost)

print(min_cost)