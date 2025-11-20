func intersectionSizeTwo(intervals [][]int) int {
    slices.SortFunc(intervals,func(a,b []int)int{
		return a[1] - b[1]
	})
	type tuple struct{
		l,r,s int
	}
	st := []tuple{{-2,-2,0}} // 哨兵
	for _,p := range intervals{
		start,end := p[0],p[1]
		i := sort.Search(len(st),func(i int)bool{
			return st[i].l >= start
		}) - 1
		d := 2 - (st[len(st)-1].s - st[i].s)
		if start <= st[i].r{
			d -= st[i].r - start + 1
		}
		if d <= 0{
			continue
		}
		for end-st[len(st)-1].r <= d{
			top := st[len(st)-1]
			st = st[:len(st) -1]
			d += top.r - top.l + 1
		}
		st = append(st,tuple{end - d + 1,end,st[len(st)-1].s + d})
	}
	return st[len(st)-1].s
}