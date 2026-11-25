# 快速幂 (Fast Power)

## 原理

计算 $a^b$ 的朴素方法是循环乘 $b$ 次, 复杂度 $O(b)$。快速幂利用二进制拆分:

$$a^b = \prod_{i:\ b\text{ 的第 } i \text{ 位为 } 1} a^{2^i}$$

每次循环将底数平方($a \to a^2 \to a^4 \to \cdots$), 指数右移一位; 当指数当前位为 1 时, 把当前底数乘入答案。

**复杂度**: 时间 $O(\log b)$, 空间 $O(1)$。

!!! warning "常见错误"
    累乘器 `res` 的初始值必须是 **1**(乘法单位元), 而不是 `base`。
    初始化为 `base` 会导致结果多乘一个 $a$, 且 $b=0$ 时返回 $a$ 而非正确的 $1$。

!!! warning "溢出"
    不带模的快速幂在 $a^b$ 较大时必然溢出 `long long`。
    带模版本若 `mod` 接近 $10^{18}$ 级别, 乘法需改为 `(__int128)x * y % mod` 防溢出。

## 模板代码

代码与仓库同步, 源文件: `Template/math/fast_power.cpp`

```cpp title="Template/math/fast_power.cpp"
--8<-- "Template/math/fast_power.cpp"
```

## 例题

| 题目 | 说明 |
| --- | --- |
| [洛谷 P1226 【模板】快速幂](https://www.luogu.com.cn/problem/P1226) | 带模快速幂板子题 |
| [洛谷 P3811 模意义下的乘法逆元](https://www.luogu.com.cn/problem/P3811) | 快速幂求逆元 $a^{p-2} \bmod p$(费马小定理) |
