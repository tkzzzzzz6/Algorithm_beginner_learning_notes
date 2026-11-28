package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)

	for ; T > 0; T-- {
		var n int
		var a, b int64
		fmt.Fscan(in, &n, &a, &b)

		A := make([]int64, n)
		var cnt0, cnt1 int64
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &A[i])
			if A[i]%2 == 0 {
				cnt0++
			} else {
				cnt1++
			}
		}

		// 只用一个点，不需要任何边
		if n == 1 {
			fmt.Fprintln(out, 0)
			continue
		}

		n64 := int64(n)
		var ans int64

		if a >= 0 && b >= 0 {
			// 情况 1：所有边非负 -> 最小生成树
			if cnt0 == 0 || cnt1 == 0 {
				// 只有一种奇偶：只能用代价 a 的边
				ans = (n64 - 1) * a
			} else {
				// 两种奇偶都有
				if b < a {
					// 奇偶边更便宜：全部用 b 搭一棵树
					ans = (n64 - 1) * b
				} else {
					// 同奇同偶边更便宜：奇堆一棵树 + 偶堆一棵树 + 一条奇偶边
					ans = (n64 - 2) * a + b
				}
			}
		} else if a < 0 && b < 0 {
			// 情况 2：所有边都是负的 -> 能加多少加多少（完全图）
			samePairs := cnt0*(cnt0-1)/2 + cnt1*(cnt1-1)/2
			crossPairs := cnt0 * cnt1
			ans = samePairs*a + crossPairs*b
		} else if a < 0 && b >= 0 {
			// 情况 3：同奇同偶边负，奇偶边非负
			if cnt0 == 0 || cnt1 == 0 {
				// 只有一种奇偶：把这一堆变成完全图
				pairsAll := n64 * (n64 - 1) / 2
				ans = pairsAll * a
			} else {
				// 两堆都存在：各自完全图 + 一条奇偶边连接
				samePairs := cnt0*(cnt0-1)/2 + cnt1*(cnt1-1)/2
				ans = samePairs*a + b
			}
		} else { // a >= 0 && b < 0
			// 情况 4：奇偶边负，同奇同偶边非负
			if cnt0 == 0 || cnt1 == 0 {
				// 没有奇偶边，只能用 a 做生成树
				ans = (n64 - 1) * a
			} else {
				// 奇偶都有：把所有奇偶负边全加
				crossPairs := cnt0 * cnt1
				ans = crossPairs * b
			}
		}

		fmt.Fprintln(out, ans)
	}
}
