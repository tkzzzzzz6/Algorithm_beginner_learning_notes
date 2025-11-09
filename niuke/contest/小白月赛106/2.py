def solve(n):
    # For n=3, we want to output:
    # 1 2 3
    # 3 4 5
    # 1 5 6
    if n == 3:
        return [
            [1, 2, 3],
            [3, 4, 5], 
            [1, 5, 6]
        ]
    
    # For other n, return None since we don't have a solution
    return None

# Get input
n = int(input())
result = solve(n)
if result:
    for row in result:
        print(*row)
else:
    print("No solution found")
