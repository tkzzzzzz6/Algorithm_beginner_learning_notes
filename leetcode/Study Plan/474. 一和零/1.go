func findMaxForm(strs []string, m int, n int) int {
	k := len(strs)
	cnt0 := make([]int, k)
	for i, s := range strs {
		cnt0[i] = strings.Count(s, "0")
	}

	memo := make([][][]int, k)
	for i := range memo {
		memo[i] = make([][]int, m+1)
		for j := range memo[i] {
			memo[i][j] = make([]int, n+1)
			for l := range memo[i][j] {
				memo[i][j][l] = -1
			}
		}
	}

	var dfs func(int, int, int) int
	dfs = func(i, j, k int) int {
		if i < 0 {
			return 0
		}
		p := &memo[i][j][k]
		if *p != -1 {
			return *p
		}
		ans := dfs(i-1, j, k)
		cnt1 := len(strs[i]) - cnt0[i]
		if j >= cnt0[i] && k >= cnt1 {
			ans = max(ans, dfs(i-1, j-cnt0[i], k-cnt1)+1)
		}
		*p = ans
		return ans
	}
	return dfs(k-1, m, n)
}

