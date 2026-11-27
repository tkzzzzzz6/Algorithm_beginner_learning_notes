# IQuest GPU 练习赛 · 2026-11-24

每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-24)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Log Softmax](https://competition.iquestlab.com/contests/practice-2026-11-24/problems/log-softmax) | Easy | 0.383264 ms | [log_softmax.cu](./log_softmax.cu) |
| B | [Lower Triangular Matrix Multiplication](https://competition.iquestlab.com/contests/practice-2026-11-24/problems/lower-trig-matmul) | Medium | 5.36435 ms | [lower_trig_matmul.cu](./lower_trig_matmul.cu) |
| C | [Matrix Multiplication with Swish Activation](https://competition.iquestlab.com/contests/practice-2026-11-24/problems/matmul-swish) | Medium | 0.208339 ms | [matmul_swish.cu](./matmul_swish.cu) |

## A · Log Softmax

对行主序的 $M\times N$ 浮点矩阵逐行计算 Log Softmax，输出与输入形状一致。令 $m_i=\max_k X_{ik}$，则 $Y_{ij}=(X_{ij}-m_i)-\log\sum_k \exp(X_{ik}-m_i)$。计算指数前减去行最大值，可以避免指数溢出。

- **测试规模** 4096×4096、6144×4096、4096×7168、4096×8192、8192×8192。
- **实现** 每个线程块处理一行，在块内分别归约最大值和指数和。常见列宽且输入、输出对齐时用 `float4` 读写，其余情况走标量路径。

![11-24 A · Log Softmax 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-24-a-log-softmax-00296f2ea00dfbaa.png)

## B · Lower Triangular Matrix Multiplication

两个输入 $A$ 和 $B$ 均为行主序的 $N\times N$ 下三角矩阵。计算 $C=AB$。当 $i\ge j$ 时，$C_{ij}=\sum_{k=j}^{i} A_{ik} B_{kj}$。主对角线上方的元素均为 0。

- **测试规模** $N$ 为 2048、4096、6144 或 8192。
- **实现** 将矩阵划分成 64×64 的输出块，用共享内存复用输入。完全位于主对角线上方的块直接写零，其余块跳过无需参与的乘积区间，并在写回时明确将上三角位置置零。

![11-24 B · Lower Triangular Matrix Multiplication 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-24-b-lower-trig-matmul-ec4b2e0cc986ddaf.png)

## C · Matrix Multiplication with Swish Activation

输入包含两个行主序矩阵 $X$ 和 $W$，形状分别为 $(B,I)$ 和 $(O,I)$，另有长度为 $O$ 的偏置 $b$ 及缩放系数 $s$。先计算 $Z=XW^{\mathsf T}+b$，再输出 $Y_{ij}=s\,Z_{ij}\,\sigma(Z_{ij})$，其中 $\sigma(z)=(1+e^{-z})^{-1}$。输出形状为 $(B,O)$。

- **测试规模** $(B,I,O,s)$ 为 $(128,1024,512,2)$、$(256,2048,1024,1.5)$、$(64,512,256,0.5)$、$(512,4096,2048,3)$ 或 $(32,256,128,1)$。
- **实现** 分块计算矩阵乘法，通过共享内存复用输入，在同一个 kernel 内加偏置、计算 Swish 并缩放，最终只写回结果。

![11-24 C · Matrix Multiplication with Swish Activation 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-24-c-matmul-swish-ddebd041b7b1b84c.png)

## 官方评测记录

| 题号 | 通过用例 | H20 总 GPU 耗时 | 得分 | 官方提交 |
| --- | ---: | ---: | ---: | --- |
| A | 5/5 | 405.97 μs | 944.0744 | [Log Softmax](https://competition.iquestlab.com/submissions/cmwumdumn3me0ymcu6s0j4chq) |
| B | 4/4 | 23.37 ms | 229.5139 | [Lower Triangular Matrix Multiplication](https://competition.iquestlab.com/submissions/cmwumd7533mvgjfcyywqynd4s) |
| C | 5/5 | 1.22 ms | 170.1150 | [Matrix Multiplication with Swish Activation](https://competition.iquestlab.com/submissions/cmwumdjyp3mxqxuf9dci7yp4n) |

队伍总分为 **1343.7033**。 [官方排行榜](https://competition.iquestlab.com/contests/practice-2026-11-24/standings)
