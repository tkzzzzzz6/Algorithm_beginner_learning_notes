def max_barrel_volume(n, heights):
    # 将木板高度与其原始索引配对
    indexed_heights = [(heights[i], i + 1) for i in range(n)]
    print(indexed_heights)
    
    # 按高度排序，以便于逐步选择最长有效的m
    indexed_heights_1 = indexed_heights.sort()
    
    max_volume = 0  # 初始化最大体积为0
    best_indices = []  # 初始化最佳索引列表为空
    
    # 从后向前滑动窗口寻找最优体积区域
    for start in range(n):
        # 计算有效的 m 和 h_min
        m = n - start  # 有效的木板数量
        h_min = indexed_heights_1[start][0]  # 当前最小高度
        volume = m * m * h_min  # 计算当前体积
        
        if volume > max_volume:  # 如果当前体积大于最大体积
            max_volume = volume  # 更新最大体积
            # 更新最佳索引列表为当前有效木板的索引
            best_indices = [indexed_heights[i][1] for i in range(start, n)]
    
    # 为保证输出顺序正确，排序索引
    best_indices.sort()  # 对最佳索引进行排序
    return len(best_indices), best_indices  # 返回最佳索引的数量和索引列表

# 获取输入
n = int(input())  # 读取木板数量
heights = list(map(int, input().split()))  # 读取木板高度

# 运行优化算法
m, indices = max_barrel_volume(n, heights)  # 调用函数计算最大体积和最佳索引

# 输出结果
print(m)  # 输出最大体积
print(' '.join(map(str, indices)))  # 输出最佳索引
