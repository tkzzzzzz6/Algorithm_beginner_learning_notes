# IQuest GPU 练习赛 · 2026-11-26

比赛时间为北京时间 11 月 26 日 10:00 至 11 月 27 日 10:00。每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-26)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [SELU](https://competition.iquestlab.com/contests/practice-2026-11-26/problems/selu) | Easy | 0.383264 ms | [selu.cu](./selu.cu) |
| B | [Softmax](https://competition.iquestlab.com/contests/practice-2026-11-26/problems/softmax) | Medium | 0.49181 ms | [softmax.cu](./softmax.cu) |
| C | [RMS Normalization](https://competition.iquestlab.com/contests/practice-2026-11-26/problems/rms-norm) | Easy | 0.083352 ms | [rms_norm.cu](./rms_norm.cu) |

## A · SELU

输入是行主序的 $M\times N$ 浮点矩阵，输出形状相同。每个元素独立应用缩放指数线性单元。$x>0$ 时返回 $\lambda x$，其余情况返回 $\lambda\alpha(e^x-1)$，其中 $\lambda\approx1.05070099$，$\alpha\approx1.67326324$。

- **测试规模** 4096×4096、6144×4096、4096×7168、4096×8192、8192×8192。
- **实现** 对齐且长度为 4 的倍数时用 `float4` 读写，其他输入按标量处理。负值分支用 `expm1f` 计算 $e^x-1$。

![11-26 A · SELU 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-26-a-selu-0b6484d25b5c94d1.png)

## B · Softmax

输入是行主序的浮点张量、维度数组 `shape`、维数 `ndim` 和从零开始的归约轴 `dim`。`shape` 也是设备指针。固定其他轴，对选定轴上的一组元素 $x$ 计算 $y_i=e^{x_i-m}/\sum_j e^{x_j-m}$，其中 $m=\max_j x_j$。输出形状与输入相同。

- **实现** 核函数在 GPU 上读取形状。连续轴使用 warp 归约并在常见尺寸下缓存中间值，跨步轴将相邻切片组成分块，合并访问后做块内归约。

| 张量形状 | 归约轴 | 输入分布 |
| --- | ---: | --- |
| (16, 128, 256) | 1 | 正态 |
| (32, 512, 512) | 2 | 均匀 |
| (8, 1024, 1024) | 1 | 正态 |
| (64, 128, 128, 128) | 2 | 均匀 |
| (4, 256, 256, 256) | 3 | 正态 |
| (128, 10) | 1 | 正态 |
| (256, 50, 50) | 0 | 均匀 |

![11-26 B · Softmax 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-26-b-softmax-e20fedeb106cd36e.png)

## C · RMS Normalization

输入是形状为 $(B,N)$ 的浮点张量 $X$。每一行独立计算特征的平方均值，输出 $Y_{bi}=X_{bi}/\sqrt{\frac1N\sum_{j=0}^{N-1}X_{bj}^2+10^{-5}}$。输出与输入形状相同。

- **测试规模** $(B,N)$ 为 $(1024,1024)$、$(1024,4096)$、$(2048,8192)$ 或 $(512,16384)$。
- **实现** 每个线程块处理一行。对常见对齐尺寸，向量化读取并在寄存器中保留行内数据，完成平方和归约后直接写回。

![11-26 C · RMS Normalization 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-26-c-rms-norm-26ea9f439a2c4c06.png)

## 本地验证

三题均在本地 RTX 4070 Laptop GPU 上通过逐元素 CPU 对照，分别覆盖 5、7、4 组题面规格，以及未对齐、零值或原地写回等边界。三份源码均通过 `sm_90` 编译。

本场于北京时间 11 月 27 日 10:00 截止，平台对 Run 返回 `Contest submissions are closed`。
