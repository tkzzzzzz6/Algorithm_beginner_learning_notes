# IQuest GPU 练习赛 · 2026-11-25

比赛时间为北京时间 11 月 25 日 10:00 至 11 月 26 日 10:00。每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-25)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Matrix Nth Power](https://competition.iquestlab.com/contests/practice-2026-11-25/problems/matrix-power) | Medium | 4.066524 ms | [matrix_power.cu](./matrix_power.cu) |
| B | [3D Max Pooling](https://competition.iquestlab.com/contests/practice-2026-11-25/problems/max-pool-3d) | Hard | 3.904795 ms | [max_pool_3d.cu](./max_pool_3d.cu) |
| C | [Minimum Spanning Tree](https://competition.iquestlab.com/contests/practice-2026-11-25/problems/min-spanning-tree) | Medium | 66.726737 ms | [min_spanning_tree.cu](./min_spanning_tree.cu) |

## A · Matrix Nth Power

输入为行主序的 $L\times L$ 浮点方阵 $A$ 及非负整数指数 $n$，输出相同形状的方阵 $A^n$。$A^0$ 为单位矩阵，$A^1=A$。

- **测试规模** $L$ 为 512、1024 或 2048，每种尺寸搭配 $n=2,4,8$。
- **实现** 按指数的二进制位做矩阵快速幂，矩阵乘法用共享内存分块和寄存器累加，全程采用 FP32。题面给出的指数均为 2 的幂，只需连续平方。

![11-25 A · Matrix Nth Power 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-25-a-matrix-power-9e789f24eb43253f.png)

## B · 3D Max Pooling

输入为行主序的 $H\times W\times D$ 浮点张量，另有窗口边长 $K$、步长 $S$、填充宽度 $P$ 和膨胀系数 $d$。各轴输入长度为 $L$ 时，对应输出长度为 $\left\lfloor(L+2P-d(K-1)-1)/S\right\rfloor+1$。每个输出取窗口内所有采样值的最大值，单轴的采样坐标为 $Si-P+dt$，其中 $i$ 是该轴输出坐标，$0\le t<K$。

- **评测口径** 官方参考调用 PyTorch `max_pool3d`，膨胀系数作用于三个轴，越界位置按负无穷处理。
- **测试规模** 三轴等长。$(L,K,S,P,d)$ 为 $(256,2,2,0,2)$、$(512,3,2,1,1)$、$(1024,4,4,2,1)$、$(512,3,3,1,3)$、$(1024,5,2,2,2)$ 或 $(1024,7,3,3,1)$。
- **实现** 在共享内存中沿三个轴依次求最大值，复用重叠窗口的中间结果。

![11-25 B · 3D Max Pooling 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-25-b-max-pool-3d-c4d20350d2a9b9f1.png)

## C · Minimum Spanning Tree

输入为带权无向图的对称邻接矩阵 $A$，形状为 $n\times n$。$A_{ij}>0$ 表示边的整数权重，$A_{ij}=0$ 表示无边。输出是最小生成树的总权重。图不连通时输出 $-1$，零个或一个顶点时输出 $0$。

- **测试规模** $n$ 为 1024、2048、4096 或 6144。
- **实现** 用 Borůvka 算法并行查找各连通分量的最轻出边，按一致的边顺序处理同权边，再用并查集合并分量并累计权重。

![11-25 C · Minimum Spanning Tree 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-25-c-min-spanning-tree-0db168c9de99db5b.png)

## 官方评测记录

| 题号 | 通过用例 | H20 总 GPU 耗时 | 得分 | 官方提交 |
| --- | ---: | ---: | ---: | --- |
| A | 9/9 | 9.07 ms | 448.3643 | [Matrix Nth Power](https://competition.iquestlab.com/submissions/cmww8qldi12bcjr64fxfci75c) |
| B | 6/6 | 10.79 ms | 361.7868 | [3D Max Pooling](https://competition.iquestlab.com/submissions/cmww8upj013k5s6pyil96ss0f) |
| C | 4/4 | 8.22 ms | 1500.0000 | [Minimum Spanning Tree](https://competition.iquestlab.com/submissions/cmww8vyhs13nb3mkxjtqyh6s6) |

队伍总分为 **2310.1511**。 [官方排行榜](https://competition.iquestlab.com/contests/practice-2026-11-25/standings)
