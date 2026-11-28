# IQuest GPU 练习赛 · 2026-11-27

比赛时间为北京时间 11 月 27 日 10:00 至 11 月 28 日 10:00。每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-27)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Image Thresholding](https://competition.iquestlab.com/contests/practice-2026-11-27/problems/threshold) | Easy | 0.114714 ms | [threshold.cu](./threshold.cu) |
| B | [Triplet Margin Loss](https://competition.iquestlab.com/contests/practice-2026-11-27/problems/triplet-margin) | Medium | 0.062683 ms | [triplet_margin.cu](./triplet_margin.cu) |
| C | [Upper Triangular Matrix Multiplication](https://competition.iquestlab.com/contests/practice-2026-11-27/problems/upper-trig-matmul) | Medium | 5.364347 ms | [upper_trig_matmul.cu](./upper_trig_matmul.cu) |

## A · Image Thresholding

输入是单通道、行主序的浮点灰度图像和阈值 $t$。像素 $x>t$ 时输出 255，$x\le t$ 时输出 0。图像尺寸不变。

- **测试规模** 1024×768、1920×1080、3840×2160，各搭配阈值 64、128、192。
- **实现** 逐像素比较，地址对齐且长度为 4 的倍数时用 `float4` 读写。

![11-27 A · Image Thresholding 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-27-a-threshold-9ddca1cc7ebb7f33.png)

## B · Triplet Margin Loss

输入是三个 $(B,E)$ 形状的嵌入张量，分别保存锚点 $a$、正样本 $p$ 和负样本 $n$，以及正间隔 $m$。输出为标量 $\frac1B\sum_{i=0}^{B-1}\max(0,d(a_i,p_i)-d(a_i,n_i)+m)$。

- **评测口径** 官方参考使用 PyTorch `TripletMarginLoss` 的默认距离。每个分量的差值先加 $10^{-6}$ 再求 L2 范数。
- **测试规模** $(B,E)$ 为 $(128,4096)$、$(256,8192)$、$(256,16384)$、$(512,8192)$ 或 $(1024,1024)$。
- **实现** 每个线程块处理一个或多个三元组，在同一遍输入读取中累计两个距离的平方和，再归约得到批次均值。

![11-27 B · Triplet Margin Loss 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-27-b-triplet-margin-ddfc06775d294cb0.png)

## C · Upper Triangular Matrix Multiplication

输入是两个行主序的 $N\times N$ 上三角矩阵 $A,B$。计算 $C=AB$。当 $i\le j$ 时，$C_{ij}=\sum_{k=i}^{j} A_{ik}B_{kj}$，当 $i>j$ 时，$C_{ij}=0$。

- **测试规模** $N$ 为 2048、4096、6144 或 8192。
- **实现** 对输入的下三角位置应用掩码，使用共享内存分块计算上三角结果。完全位于主对角线下方的输出块直接置零。

![11-27 C · Upper Triangular Matrix Multiplication 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-27-c-upper-trig-matmul-11caa53a24963df6.png)

## 官方评测记录

| 题号 | 通过用例 | H20 总 GPU 耗时 | 得分 | 官方提交 |
| --- | ---: | ---: | ---: | --- |
| A | 9/9 | 108.00 μs | 1062.1716 | [Image Thresholding](https://competition.iquestlab.com/submissions/cmwz9avbr5sqxrgr16syeq83d) |
| B | 5/5 | 90.10 μs | 695.7318 | [Triplet Margin Loss](https://competition.iquestlab.com/submissions/cmwz9a71m5r2rujxm5mzacwi5) |
| C | 4/4 | 20.41 ms | 262.8739 | [Upper Triangular Matrix Multiplication](https://competition.iquestlab.com/submissions/cmwz99mie5qpwujxm10zcy7fz) |

队伍总分为 **2020.7773**。 [官方排行榜](https://competition.iquestlab.com/contests/practice-2026-11-27/standings)
