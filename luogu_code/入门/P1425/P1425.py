a, b, c, d = map(int, input().split())

start_time = a * 60 + b
end_time = c * 60 + d

# 如果结束时间比开始时间早，说明时间跨越了午夜
if end_time < start_time:
    end_time += 24 * 60

use_time = end_time - start_time

e = use_time // 60
f = use_time % 60

print(f"{e} {f}")