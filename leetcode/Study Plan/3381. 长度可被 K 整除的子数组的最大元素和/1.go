func maxSubarraySum(nums []int, k int) int64 {
    sum := make([]int,len(nums)+1)
	// calculate prefix sum
	for i,x := range nums{
		sum[i+1] = sum[i]+x
	}
	minSum := make([]int,k)
	for i:= range minSum{
		minSum[i] = math.MaxInt64/2
	}
	ans := math.MinInt
	for j,s := range sum{
		i := j%k
		ans = max(ans,s-minSum[i])
		minSum[i] = min(minSum[i],s)
	}
	return int64(ans)
}
