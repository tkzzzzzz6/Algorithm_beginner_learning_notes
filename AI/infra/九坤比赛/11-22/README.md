# IQuest GPU 练习赛 · 2026-11-22

每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-22)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Hinge Loss](https://competition.iquestlab.com/contests/practice-2026-11-22/problems/hinge-loss) | Easy | 0.298528 ms | [hinge_loss.cu](./hinge_loss.cu) |
| B | [Image Histogram](https://competition.iquestlab.com/contests/practice-2026-11-22/problems/histogram) | Easy | 0.199113 ms | [histogram.cu](./histogram.cu) |
| C | [Huber Loss](https://competition.iquestlab.com/contests/practice-2026-11-22/problems/huber-loss) | Easy | 0.298528 ms | [huber_loss.cu](./huber_loss.cu) |

## A · Hinge Loss

输入为长度均为 `N` 的两个连续 `float` 向量 `predictions` 和 `targets`。每个目标值为 $-1$ 或 $1$。输出是长度为 `N` 的逐元素损失，$\mathrm{output}_i=\max(0,1-\mathrm{predictions}_i\,\mathrm{targets}_i)$。

- **测试规模** `N` 为 1,048,576、4,194,304、16,777,216 或 67,108,864。
- **实现** 逐元素计算并直接写回。对齐时用 `float4` 读写，其余元素按标量处理。

![11-22 A · Hinge Loss 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-22-a-hinge-loss-ab2f55b783ee9ac7.png)

## B · Image Histogram

输入为单通道 `float` 图像和桶数 `num_bins`。像素值是 `[0, num_bins-1]` 范围内的整数。输出长度为 `num_bins`，第 `k` 个元素统计像素值恰好等于 `k` 的次数。

- **测试规模** 2560×1440、2048×2048、4096×4096 三种图像尺寸，各搭配 64、128、256 桶。
- **实现** 每个 warp 在共享内存中累加自己的直方图，合并后写入全局输出。大计数采用整数累加，再转换为 `float`。

![11-22 B · Image Histogram 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-22-b-histogram-077fb81eb23d02bf.png)

## C · Huber Loss

输入为长度均为 `N` 的两个连续 `float` 向量 `predictions` 和 `targets`，输出长度为 `N`。阈值固定为 $\delta=1$。令 $d=|\mathrm{predictions}_i-\mathrm{targets}_i|$，当 $d<1$ 时输出 $0.5d^2$，其余情况输出 $d-0.5$。

- **测试规模** `N` 为 1,048,576、4,194,304、16,777,216 或 67,108,864。
- **实现** 计算绝对差并按阈值分段输出，对齐时采用 `float4` 读写。

![11-22 C · Huber Loss 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-22-c-huber-loss-8ba54211d50da0a9.png)

## 官方评测记录

| 题号 | 通过用例 | H20 总 GPU 耗时 | 得分 | 官方提交 |
| --- | ---: | ---: | ---: | --- |
| A | 4/4 | 354.22 μs | 842.7662 | [Hinge Loss](https://competition.iquestlab.com/submissions/cmwr70ml9zsftzp2qh5uy45a9) |
| B | 9/9 | 1.14 ms | 174.6679 | [Image Histogram](https://competition.iquestlab.com/submissions/cmwr727rnzwlp92rsxxzptmts) |
| C | 4/4 | 355.41 μs | 839.9586 | [Huber Loss](https://competition.iquestlab.com/submissions/cmwr71c3nzsbj35687yhu6ymk) |

队伍总分为 **1857.3927**。 [官方排行榜](https://competition.iquestlab.com/contests/practice-2026-11-22/standings)
