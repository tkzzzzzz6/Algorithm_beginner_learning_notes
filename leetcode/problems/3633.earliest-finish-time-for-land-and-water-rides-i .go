/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 09:09:17
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 09:13:50
 */
func solve(landStartTime,landDuration,waterStartTime,waterDuration []int)int{
	minFinish := math.MaxInt
	for i,start := range landStartTime{
		minFinish = min(minFinish,start + landDuration[i])
	}

	res := math.MaxInt
	for i,start := range waterStartTime{
		res = min(res,max(start,minFinish) + waterDuration[i])
	}

	return res
}

func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    land2water := solve(landStartTime,landDuration,waterStartTime,waterDuration)
	water2land := solve(waterStartTime,waterDuration,landStartTime,landDuration)

	return min(land2water,water2land)
}
