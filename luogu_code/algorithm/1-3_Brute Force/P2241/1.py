# 读取输入，使用input()函数获取用户输入的字符串，并用split()方法将其分割成多个部分，再用map()函数将其转换为整数
n, m = map(int, input().split())

# 初始化计数器，分别用于计数正方形和长方形的数量
cnt_square = 0    # 正方形计数
cnt_rectangle = 0 # 长方形计数

sum_all = (m +1) *m//2*(n+1)*n//2;
for i in range(1, min(n,m)+1):
    cnt_square +=(m-i+1)*(n-i+1)
cnt_rectangle = sum_all - cnt_square

# 输出结果，使用print()函数输出正方形和长方形的数量
print(cnt_square, cnt_rectangle)        