from datetime import datetime, timedelta

# 读取输入
s, v = map(int, input().split())

# 计算所需时间（分钟）
t = s / v + 10

# 当前时间为 08:00
current_time = datetime.strptime("08:00", "%H:%M")

# 计算最晚出发时间
latest_departure_time = current_time - timedelta(minutes=t)

# 格式化输出
formatted_time = latest_departure_time.strftime("%H:%M")
print(formatted_time)