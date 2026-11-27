# IQuest GPU 练习赛 · 2026-11-23

每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-23)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Kullback-Leibler Divergence](https://competition.iquestlab.com/contests/practice-2026-11-23/problems/kl-loss) | Medium | 0.306805 ms | [kl_loss.cu](./kl_loss.cu) |
| B | [Layer Normalization](https://competition.iquestlab.com/contests/practice-2026-11-23/problems/layer-norm) | Medium | 0.14247 ms | [layer_norm.cu](./layer_norm.cu) |
| C | [Leaky ReLU](https://competition.iquestlab.com/contests/practice-2026-11-23/problems/leaky-relu) | Easy | 0.389528 ms | [leaky_relu.cu](./leaky_relu.cu) |

## A · Kullback-Leibler Divergence

输入是长度均为 $N$ 的连续浮点向量 $P=\mathrm{targets}$ 和 $Q=\mathrm{predictions}$，两者元素分别求和为 1。$P_i\geq0$，$Q_i>0$。输出第 $i$ 项是 $P_i(\log P_i-\log Q_i)$，约定 $P_i=0$ 时输出 0。所有输出项相加即可得到 $D_{\mathrm{KL}}(P\parallel Q)$。

- **测试规模** $N$ 为 1,048,576、4,194,304、16,777,216 或 67,108,864，另有稀疏目标分布。
- **实现** 按官方参考程序对两个输入的取值使用 $10^{-10}$ 下限，再对原始目标值为零的位置直接写零。对齐且长度为 4 的倍数时按 `float4` 读写，其余情况按标量处理。

![11-23 A · Kullback-Leibler Divergence 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-23-a-kl-loss-2ef1dba78a15c8db.png)

## B · Layer Normalization

输入 $X$ 的形状是 $(B,F,D_1,D_2)$，缩放参数 $\gamma$ 和偏移参数 $\beta$ 的形状均为 $(F,D_1,D_2)$。对每个批次样本独立计算后三个维度的均值 $\mu$ 和总体方差 $\sigma^2$，输出 $Y=(X-\mu)\gamma/\sqrt{\sigma^2+10^{-5}}+\beta$，形状和 $X$ 一致。

- **测试规模** $(B,F,D_1,D_2)$ 为 $(16,64,32,32)$、$(32,128,64,64)$、$(8,256,128,128)$ 或 $(4,512,32,32)$。
- **实现** 先以样本首元素为偏移，再用双精度并行归约计算均值和方差，降低输入整体偏移较大时的消减误差。归一化后融合逐元素缩放和偏移。

![11-23 B · Layer Normalization 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-23-b-layer-norm-b336206e62f3c377.png)

## C · Leaky ReLU

输入是行主序的 $M\times N$ 浮点矩阵及系数 $\alpha$，输出形状不变。当 $x>0$ 时输出 $x$，其余情况输出 $\alpha x$。

- **测试规模** 4096×4096、6144×4096，各搭配 $\alpha\in\{0.01,0.05,0.1,0.2\}$。
- **实现** 直接逐元素计算，对齐时按 `float4` 读写，未对齐输入和最后不足 4 个的元素按标量处理。

![11-23 C · Leaky ReLU 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-23-c-leaky-relu-1991c11ba35c3c26.png)

## 本地验证

比赛于北京时间 11 月 24 日 10:00 结束，官方提交已关闭。三题均在本地 RTX 4070 Laptop GPU 上通过题面列出的测试规模和参数组合，并与独立 CPU 参考实现对照。另测了 A 的零值与稀疏输入、B 的常数输入与大偏移、C 的未对齐输入和尾部元素。
