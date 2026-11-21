# IQuest GPU 练习赛 · 2026-11-18

比赛于北京时间 2026 年 11 月 19 日 10:00 结束。平台使用 NVIDIA H20。每题基础分为 1000 分，上限为 1500 分，按 `1000 × min(1.5, T_std / 总 GPU 耗时)` 计分并保留 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-18)

| 题号 | 官方题面                                                                                                       | 难度   | 题面基准总 GPU 耗时 | CUDA 源码                                       |
| ---- | -------------------------------------------------------------------------------------------------------------- | ------ | ------------------: | ----------------------------------------------- |
| A    | [3D Square Convolution](https://competition.iquestlab.com/contests/practice-2026-11-18/problems/conv-square-3d) | Hard   |         3.950804 ms | [conv_square_3d.cu](./conv_square_3d.cu)         |
| B    | [Cosine Similarity](https://competition.iquestlab.com/contests/practice-2026-11-18/problems/cosine-similarity)  | Easy   |          0.35209 ms | [cosine_similarity.cu](./cosine_similarity.cu)   |
| C    | [Cumulative Product](https://competition.iquestlab.com/contests/practice-2026-11-18/problems/cumprod)           | Medium |         0.029233 ms | [cumulative_product.cu](./cumulative_product.cu) |

## A · 3D Square Convolution

把 `K × K × K` 卷积核 `B` 的中心对准输入体 `A` 的每个位置，将覆盖的值与对应权重相乘再求和。令 `r = K / 2`，公式中的输入位置为 `A[i + x - r][j + y - r][k + z - r]`，超出边界取零。权重顺序与官方 `torch.nn.functional.conv3d` 参考一致。

- **输入** 行优先存储的 `float` 输入体 `A` 和卷积核 `B`，边长分别为 `size` 与 `K`。`K` 是小于 `size` 的奇数。
- **输出** 行优先存储的 `size × size × size` 的 `float` 输出体 `C`。
- **测试规模** `(size, K)` 为 `(64, 3)`、`(32, 9)`、`(96, 11)`、`(128, 5)`、`(256, 7)`、`(512, 9)`。
- **实现** 用共享内存缓存每块输入及其边界邻域，一次为同一深度方向上的四个位置累加，常见核尺寸有专用路径。

![11-18 A · 3D Square Convolution 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-18-a-conv-square-3d-9f51febddb8d859c.png)

## B · Cosine Similarity

对 `predictions` 与 `targets` 的第 `i` 行计算 `1 - dot(x, y) / (max(1e-8, norm(x)) * max(1e-8, norm(y)))`。`norm` 为 L2 范数，两个范数各自应用下限。

- **输入** 两个形状为 `n × d` 的 `float` 矩阵 `predictions` 与 `targets`。
- **输出** 长度为 `n` 的 `float` 向量，每行对应一个距离值。例如，两行均为 `[1, 0]` 时结果为 `0`，任一输入向量为零时结果为 `1`。
- **测试规模** `d = 4096`，`n` 为 4096、8192、10240、16384。
- **实现** 每个线程块归约一行，同时累加点积和两行的平方和。列数和地址满足对齐条件时用 `float4` 读取。

![11-18 B · Cosine Similarity 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-18-b-cosine-similarity-0c55a26d011a5daf.png)

## C · Cumulative Product

计算包含当前位置的前缀乘积。`output[i]` 等于 `input[0]` 到 `input[i]` 的乘积，第一个输出元素等于第一个输入元素。

- **输入** 长度为 `N` 的 `float` 向量 `input`。
- **输出** 长度为 `N` 的 `float` 向量 `output`。例如，`[2, -3, 4, 0]` 得到 `[2, -6, -24, 0]`。
- **测试规模** `N` 为 65,536、131,072、262,144、524,288、1,048,576。
- **实现** 先扫描块内乘积，再扫描块尾乘积并补上跨块前缀。浮点并行分组在极端溢出或下溢附近可能与参考结果有差异。

![11-18 C · Cumulative Product 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-18-c-cumprod-bf8abfc60ee18e75.png)

## 验证记录

平台在 B 题点击 **Run** 后返回 `Contest submissions are closed`，本场官方提交和 H20 评测入口已关闭。

三份源码均通过 CUDA 11.8 编译，并在本机 RTX 4070 Laptop 上与独立的 CPU 参考结果对比。

- **A** 覆盖题面全部 6 组尺寸。逐元素验证非对称稀疏核，另外用小规模随机输入和核检查密集计算。
- **B** 覆盖题面全部 4 组尺寸。这 4 组与双精度 CPU 参考相比，最大绝对误差为 `6.37e-8`。另外检查零范数、非整列和未按 16 字节对齐的输入。
- **C** 通过 18 项本机检查，覆盖题面全部 5 个长度，以及尾块、零、负数和原地计算。
