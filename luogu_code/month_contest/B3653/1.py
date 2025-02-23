n,m = map(int,input().split())

class Gopher:
    def __init__(self,row,col,score):
        self.row = row
        self.col = col
        self.score = score
        self.max_distance = 0  # 初始化最大距离为0

def calc_distance_square(gopher1,gopher2):
    return (gopher1.row - gopher2.row) ** 2 + (gopher1.col - gopher2.col) ** 2

# 创建一个二维列表来存储 Gopher 对象
gophers = [[None for _ in range(m)] for _ in range(n)]

# 创建一个字典来存储相同分数的地鼠
score_groups = {}

# 读取输入并创建Gopher对象
for i in range(n):
    scores = list(map(int, input().split()))
    for j, score in enumerate(scores):
        gopher = Gopher(i, j, score)
        gophers[i][j] = gopher
        if score not in score_groups:
            score_groups[score] = []
        score_groups[score].append(gopher)

# 计算每个地鼠与同分数地鼠的最大距离
for score, group in score_groups.items():
    for gopher in group:
        for other in group:
            if gopher != other:
                distance = calc_distance_square(gopher, other)
                gopher.max_distance = max(gopher.max_distance, distance)

# 输出结果
for i in range(n):
    for j in range(m):
        gopher = gophers[i][j]
        print(gopher.max_distance, end=' ')
    print()  # 换行
