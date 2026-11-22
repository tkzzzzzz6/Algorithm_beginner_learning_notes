# IQuest GPU 练习赛 · 2026-11-20

比赛于北京时间 2026 年 11 月 21 日 10:00 结束。评测使用 NVIDIA H20。每题基础分为 1000 分，最高为 1500 分，得分为 `1000 × min(1.5, T_std / 总 GPU 耗时)`，四舍五入到 4 位小数。 [比赛主页](https://competition.iquestlab.com/contests/practice-2026-11-20)

| 题号 | 官方题面 | 难度 | 基准总 GPU 耗时 | CUDA 源码 |
| --- | --- | --- | ---: | --- |
| A | [Edge Detection](https://competition.iquestlab.com/contests/practice-2026-11-20/problems/edge-detect) | Easy | 0.082329 ms | [edge_detect.cu](./edge_detect.cu) |
| B | [ELU](https://competition.iquestlab.com/contests/practice-2026-11-20/problems/elu) | Easy | 0.383264 ms | [elu.cu](./elu.cu) |
| C | [Frobenius Normalization](https://competition.iquestlab.com/contests/practice-2026-11-20/problems/frobenius-norm) | Easy | 0.134688 ms | [frobenius_norm.cu](./frobenius_norm.cu) |

## A · Edge Detection

对单通道灰度图像做边缘检测。在内部像素用左右邻居差的一半计算 $G_x$，用上下邻居差的一半计算 $G_y$，梯度幅值为 $G=\sqrt{G_x^2+G_y^2}$。外围一圈输出为零。按官方参考实现，当全图最大幅值 $G_{\max}>0$ 时，输出 $(G/G_{\max})\cdot255$。全图幅值为零时输出保持为零。

- **输入** 形状为 `height × width` 的 `float` 灰度图像。
- **输出** 与输入同形状的 `float` 边缘图。
- **测试规模** 1024×768、1920×1080、2048×2048、2560×1440、4096×4096。
- **实现** 先计算梯度幅值和各线程块的局部最大值，再归约全图最大幅值，最后统一缩放。

![11-20 A · Edge Detection 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-20-a-edge-detect-65f6f8ef8da1edaa.png)

## B · ELU

对矩阵逐元素应用 ELU 激活。正数直接输出，非正数输出 $\alpha(e^x-1)$。题面的默认参数为 $\alpha=1$，CUDA 接口直接接收 `alpha`。

- **输入** 按行优先存储的 `float` 矩阵 `A` 和 `float` 参数 `alpha`。
- **输出** 与输入同形状、同样按行优先存储的 `float` 矩阵 `C`。
- **测试规模** 4096×4096、6144×4096、4096×7168、4096×8192、8192×8192。
- **实现** 元素独立计算。用 `expm1f(x)` 提高接近零时的精度，对齐且元素数可被 4 整除时用 `float4` 读写。

![11-20 B · ELU 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-20-b-elu-4f38b0e6edca751c.png)

## C · Frobenius Normalization

把任意形状的张量视为一维数组，对全部元素计算一个 Frobenius 范数 $\lVert X\rVert_F=\sqrt{\sum_i X_i^2}$。输出的每个元素为 $Y_i=X_i/\lVert X\rVert_F$。

- **输入** `float` 张量 `X` 及元素总数 `size`。
- **输出** 与输入同形状的 `float` 张量 `Y`。官方参考直接除以范数，全零输入时输出为 NaN。
- **测试规模** `(4, 1024, 1024)`、`(32, 128, 128)`、`(8, 32, 256, 256)`、`(4, 16, 32, 128, 128)`。
- **实现** 按线程块累加平方和，再归约并算出范数的倒数，最后逐元素缩放。

![11-20 C · Frobenius Normalization 官方题面](https://tk-pichost-1325224430.cos.ap-chengdu.myqcloud.com/blog/iquest-practice-2026-11/iquest-2026-11-20-c-frobenius-norm-f7269f9c76df107c.png)

## 评测状态

本场比赛已结束。下面的验证使用本机 RTX 4070 Laptop 和 CUDA 11.8，输入由本地测试生成，结果与 CPU 参考对照。

| 题号 | 通过用例 | 验证覆盖 |
| --- | ---: | --- |
| A | 17/17 | 全部 5 组题面尺寸、零边框、常量图像和窄图像 |
| B | 10/10 | 全部 5 组题面尺寸、自定义 `alpha`、非对齐地址和原地执行 |
| C | 10/10 | 全部 4 组题面尺寸、零范数、非对齐地址和原地执行 |
