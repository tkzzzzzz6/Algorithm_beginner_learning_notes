# 输入：t是背包容量，m是物品数量
t, m = map(int, input().split())

T = []  
V = []

# 输入m个物品的体积和价值
for i in range(m):
    e1, e2 = map(int, input().split())
    T.append(e1)  
    V.append(e2)  

# DP数组：dp[j]表示容量为j时的最大价值
dp = [0] * (t + 1)  

# 完全背包：每个物品可以选多次
for i in range(m):
    for j in range(T[i], t + 1):  
        dp[j] = max(dp[j], dp[j - T[i]] + V[i])

# 输出容量为t时的最大价值
print(dp[t])