# IQuest GPU 练习赛 · 2026-11-19

比赛使用 NVIDIA H20。每题基础分为 1000 分，上限为 1500 分。得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。表中是归档时题面显示的基准用时，平台更新基准后会重新计分。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-19)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Cumulative Sum](https://competition.iquestlab.com/contests/practice-2026-11-19/problems/cumsum) | Medium | 0.029233 ms | [cumulative_sum.cu](./cumulative_sum.cu) |
| B | [Diagonal Matrix Multiplication](https://competition.iquestlab.com/contests/practice-2026-11-19/problems/diagonal-matmul) | Easy | 0.212261 ms | [diagonal_matmul.cu](./diagonal_matmul.cu) |
| C | [ECC Point Negation (Batched)](https://competition.iquestlab.com/contests/practice-2026-11-19/problems/ecc-point-negation) | Easy | 0.044576 ms | [ecc_point_negation.cu](./ecc_point_negation.cu) |

## A · Cumulative Sum

计算包含当前位置的前缀和。`output[i]` 等于 `input[0]` 到 `input[i]` 的总和，第一个输出元素等于第一个输入元素。

- **输入** 长度为 `N` 的 `float` 向量 `input`。
- **输出** 长度为 `N` 的 `float` 向量 `output`。例如，`[3, -1, 2, 4]` 得到 `[3, 2, 4, 8]`。
- **测试规模** `N` 为 65,536、131,072、262,144、524,288、1,048,576。
- **实现** 对齐且协同网格能同时驻留时，使用单次协同 kernel 合并块内扫描和跨块前缀。其他情况使用 1024 元素分块，依次执行块内扫描、块尾扫描和跨块补偿。两条路径都直接复用输出缓冲区存放块和。

![11-19 A · Cumulative Sum 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-19-a-cumsum-cf0aac8f3b0080ec.png)

## B · Diagonal Matrix Multiplication

计算对角矩阵 `diag(A)` 左乘矩阵 `B` 的结果。每个输出元素满足 `C[i][j] = A[i] * B[i][j]`，也就是用 `A[i]` 缩放 `B` 的第 `i` 行。

- **输入** 长度为 `n` 的 `float` 向量 `A`，以及形状为 `n × m` 的 `float` 矩阵 `B`。
- **输出** 形状为 `n × m` 的 `float` 矩阵 `C`。`B` 和 `C` 都按行连续存储。比如 `A = [2, 3]`，`B = [[1, 4], [2, 6]]`，则 `C = [[2, 8], [6, 18]]`。
- **测试规模** `(n, m)` 为 `(2048, 2048)`、`(4096, 4096)`、`(6144, 6144)`、`(8192, 4096)`。
- **实现** 单次 kernel 按行缩放。对齐时使用 `float4`，根据行宽选择分块大小和缓存策略，其他情况逐元素处理。

![11-19 B · Diagonal Matrix Multiplication 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-19-b-diagonal-matmul-1b47b06fba94377a.png)

## C · ECC Point Negation (Batched)

对曲线 $y^2 \equiv x^3 + 7 \pmod p$ 上的一批点取负，其中 $p = 2^{61} - 1$。对每个点保留 `x`，把 `y` 换成 `(p - y) % p`。`y` 为 `0` 时结果仍为 `0`。

- **输入** 两个长度为 `n` 的 `uint64_t` 数组 `xs` 和 `ys`，每个坐标都在 `[0, p)` 内。函数还接收模数 `p` 和批大小 `n`。
- **输出** 长度为 `2*n` 的 `uint64_t` 数组 `out_xy`。`out_xy[2*i] = xs[i]`，`out_xy[2*i + 1] = (p - ys[i]) % p`。
- **测试规模** `n` 为 262,144、524,288、1,048,576、2,097,152。
- **实现** 输出地址满足 16 字节对齐时，每个线程处理两个点，每个点的两个坐标合并写入。其余情况用逐点路径。

![11-19 C · ECC Point Negation (Batched) 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-19-c-ecc-point-negation-810992621fc193ba.png)

## 官方评测记录

下表记录 2026 年 11 月 19 日优化前后的队伍最高分。三份源码对应各自最快的 H20 提交。

| 题号 | 通过用例 | 总 GPU 耗时 | 得分 | 官方提交 |
| --- | ---: | ---: | ---: | --- |
| A | 5/5 | 123.74 → 87.25 μs | 236.2377 → 335.0564 | [协同扫描](https://competition.iquestlab.com/submissions/cmwn95mqdjlte92rsn4tjbmax) |
| B | 4/4 | 285.46 → 273.31 μs | 743.5857 → 776.6253 | [按行宽分块](https://competition.iquestlab.com/submissions/cmwn96sgcjnija7s3l06mqh5g) |
| C | 4/4 | 93.36 → 90.30 μs | 477.4636 → 493.6215 | [双点并行](https://competition.iquestlab.com/submissions/cmwn91enjjish11xzqtstm2wj) |

队伍总分从 **1457.2870** 提高到 **1605.3032**，增加 **148.0162** 分。 [官方排行榜](https://competition.iquestlab.com/contests/practice-2026-11-19/standings)
