import sys
input = sys.stdin.readline

def solve():
    # 读取输入字符串，去掉首尾空白字符
    s = input().strip()
    # 如果字符串为空，则输出0并返回
    if not s:
        print(0)
        return

    runs = []  # 存储每个连续区段的字符和长度
    prev = s[0]  # 当前区段的字符
    cnt = 1      # 当前区段的长度
    # 遍历字符串，其余部分
    for c in s[1:]:
        if c == prev:  # 如果和上一字符相同，区段长度加一
            cnt += 1
        else:
            runs.append((prev, cnt))  # 否则保存当前区段
            prev = c                  # 更新当前字符
            cnt = 1                   # 重置计数
    runs.append((prev, cnt))  # 最后一个区段记得保存

    ans = 0
    # 只检查相邻两段（连续不同字符）
    for i in range(len(runs) - 1):
        d1, L = runs[i]       # 第i段的字符和长度
        d2, R = runs[i + 1]   # 第i+1段的字符和长度
        # 如果后一个字符的ASCII码正好比前一个大1（如'a'和'b'）
        if ord(d2) == ord(d1) + 1:    
            m = min(L, R)  # 能成对的最大数量是两段长度较小值
            # 对于所有长度为k（1到m）的配对计算组合数
            # Σ_{k=1..m} (L - k + 1)
            # 化简为 m*L - m*(m-1)/2
            ans += m * L - m * (m - 1) // 2

    print(ans)

if __name__ == "__main__":
    solve()
