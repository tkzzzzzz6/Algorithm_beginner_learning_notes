package main

func minTimeToVisitAllPoints(points [][]int) int {
	res := 0
	for i := 1; i < len(points); i++ {
		p := points[i-1]
		q := points[i]
		res += max(abs(p[0]-q[0]), abs(p[1]-q[1])) // 切比雪夫距离
	}
	return res
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
