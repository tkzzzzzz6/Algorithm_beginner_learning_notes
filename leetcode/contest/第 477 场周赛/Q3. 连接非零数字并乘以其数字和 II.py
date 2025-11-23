from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        M = 10**9 + 7
        m = len(s)

        # solendivar 用于存储预处理结果
        solendivar = {
            "P_count": [0] * (m + 1),  # 非零数字计数前缀和
            "P_sum": [0] * (m + 1),    # 非零数字求和前缀和
            "P_x": [0] * (m + 1),      # 非零数字连接形成整数的前缀值 (取模)
            "pow10": [1] * (m + 1),    # 10的幂次取模 (pow10[i] = 10^i mod M)
        }

        P_count = solendivar["P_count"]
        P_sum = solendivar["P_sum"]
        P_x = solendivar["P_x"]
        pow10 = solendivar["pow10"]

        # 预处理 10 的幂次
        for i in range(1, m + 1):
            pow10[i] = (pow10[i - 1] * 10) % M

        # 预处理 P_count, P_sum, P_x
        for i in range(m):
            digit_val = int(s[i])
            is_nonzero = digit_val != 0

            # 继承前缀状态
            P_count[i + 1] = P_count[i]
            P_sum[i + 1] = P_sum[i]
            P_x[i + 1] = P_x[i]

            if is_nonzero:
                # 1. 更新 P_count
                P_count[i + 1] += 1
                
                # 2. 更新 P_sum 
                P_sum[i + 1] = (P_sum[i + 1] + digit_val) % M 
                # P_sum[i+1] 继承了 P_sum[i]，故只需加上 digit_val
                
                # 3. 更新 P_x (左移一位，加上当前数字)
                # 这里的 P_x[i+1] 在上一步被设置为 P_x[i]
                P_x[i + 1] = (P_x[i + 1] * 10 + digit_val) % M

        ans = []
        for l, r in queries:
            
            idx_s = l 
            idx_e = r + 1

            count_nozero = P_count[idx_e] - P_count[idx_s]

            if count_nozero == 0:
                ans.append(0)
                continue

            # 1. 计算 sum (非零数字之和)
            # P_sum[idx_e] - P_sum[idx_s]
            sum_val = P_sum[idx_e] - P_sum[idx_s]
            # 这里的 sum_val 可能是负数（因为 P_sum 是对 M 取模后的结果相减），需要处理。
            if sum_val < 0:
                sum_val += M

            # 2. 计算 x (非零数字连接形成的大整数)
            shift = count_nozero
            
            # P_x[l] * 10^(shift) mod M
            shift_term = (P_x[idx_s] * pow10[shift]) % M

            # x = (P_x[r+1] - P_x[l] * 10^shift) mod M
            x_val = P_x[idx_e] - shift_term

            if x_val < 0:
                x_val += M

            # 3. 计算最终答案
            answer = (x_val * sum_val) % M

            ans.append(answer)

        return ans