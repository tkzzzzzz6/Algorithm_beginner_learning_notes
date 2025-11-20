func intersectionSizeTwo(intervals [][]int) int {
    slices.SortFunc(intervals, func(a, b []int) int { return a[1] - b[1] })
    // 栈中保存闭区间左右端点，栈底到栈顶的区间长度的和
    type tuple struct{ l, r, s int }
    st := []tuple{{-2, -2, 0}} // 哨兵，保证不和任何区间相交
    for _, p := range intervals {
        start, end := p[0], p[1]
        i := sort.Search(len(st), func(i int) bool { return st[i].l >= start }) - 1
        d := 2 - (st[len(st)-1].s - st[i].s) // 去掉运行中的时间点
        if start <= st[i].r { // start 在区间 st[i] 内
            d -= st[i].r - start + 1 // 去掉运行中的时间点
        }
        if d <= 0 {
            continue
        }
        for end-st[len(st)-1].r <= d { // 剩余的 d 填充区间后缀
            top := st[len(st)-1]
            st = st[:len(st)-1]
            d += top.r - top.l + 1 // 合并区间
        }
        st = append(st, tuple{end - d + 1, end, st[len(st)-1].s + d})
    }
    return st[len(st)-1].s
}

