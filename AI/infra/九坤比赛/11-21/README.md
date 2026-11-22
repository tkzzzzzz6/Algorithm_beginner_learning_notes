# IQuest GPU 练习赛 · 2026-11-21

每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-21)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [GELU](https://competition.iquestlab.com/contests/practice-2026-11-21/problems/gelu) | Easy | 0.383264 ms | [gelu.cu](./gelu.cu) |
| B | [GEMM with Bias and ReLU](https://competition.iquestlab.com/contests/practice-2026-11-21/problems/gemm-relu) | Medium | 1.75299 ms | [gemm_relu.cu](./gemm_relu.cu) |
| C | [Hard Sigmoid](https://competition.iquestlab.com/contests/practice-2026-11-21/problems/hard-sigmoid) | Easy | 0.383264 ms | [hard_sigmoid.cu](./hard_sigmoid.cu) |

## A · GELU

对按行优先存储的 `float` 矩阵逐元素应用 GELU，将结果写入同形状的输出矩阵。题目要求使用近似式 $\tfrac12 x(1+\tanh(\sqrt{2/\pi}(x+0.044715x^3)))$。

- **测试规模** 4096×4096、6144×4096、4096×7168、4096×8192、8192×8192。
- **实现** 用 `tanhf` 计算近似式，对齐时用 `float4` 连续读写。

![11-21 A · GELU 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-21-a-gelu-a1677db2b3336e8e.png)

## B · GEMM with Bias and ReLU

输入矩阵 $A$ 为 $B\times N$，权重 $W$ 为 $M\times N$，偏置向量 $b$ 长度为 $M$。三个矩阵 $A$、$W$、$C$ 均按行优先存储。输出 $C$ 的形状为 $B\times M$，其中 $C_{ij}=\max(0,\sum_{k=0}^{N-1}A_{ik}W_{jk}+b_j)$。

- **测试规模** `(B, N, M)` 为 `(512, 6144, 1024)`、`(512, 8192, 1024)`、`(512, 8192, 2048)`、`(1024, 2048, 2048)`、`(1024, 4096, 2048)`、`(1024, 4096, 4096)`。
- **实现** 以共享内存分块加载输入和权重，在寄存器累加，写出时融合偏置和 ReLU。

![11-21 B · GEMM with Bias and ReLU 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-21-b-gemm-relu-1df74c6ac95aa257.png)

## C · Hard Sigmoid

对按行优先存储的 `float` 矩阵逐元素应用 Hard Sigmoid。$x\le -3$ 时输出 0，$x\ge 3$ 时输出 1，其他值输出 $(x+3)/6$。输出矩阵与输入形状相同。

- **测试规模** 4096×4096、6144×4096、4096×7168、4096×8192、8192×8192。
- **实现** 对齐时按 `float4` 读写，有尾部或非对齐地址时走标量路径。

![11-21 C · Hard Sigmoid 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-21-c-hard-sigmoid-c46168c92005ecca.png)

## 官方评测记录

| 题号 | 通过用例 | H20 总 GPU 耗时 | 得分 | 官方提交 |
| --- | ---: | ---: | ---: | --- |
| A | 5/5 | 479.46 μs | 799.3726 | [GELU](https://competition.iquestlab.com/submissions/cmwr60w8xznmia7s38987tkcj) |
| B | 6/6 | 7.55 ms | 232.1473 | [GEMM with Bias and ReLU](https://competition.iquestlab.com/submissions/cmwr60c5szjyw3568qu5cta8l) |
| C | 5/5 | 495.39 μs | 773.6580 | [Hard Sigmoid](https://competition.iquestlab.com/submissions/cmwr5zjrzzjra3568m832hjhp) |

队伍总分为 **1805.1779**。 [官方排行榜](https://competition.iquestlab.com/contests/practice-2026-11-21/standings)
