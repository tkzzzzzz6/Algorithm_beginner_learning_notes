func numberOfPaths(grid [][]int,k int)int{
	const mod = 1_000_000_007
	m,n := len(grid),len(grid[0])
	f := make([][][]int,m+1)
	for i := range f{
		f[i] = make([][]int,n+1)
		for j := range f[i]{
			f[i][j] = make([]int,k)
		}
	}
	f[0][1][0] = 1
	for i,row := range grid{
		for j,x := range row{
			for s:=range k{
				newS := (s+x)%k
				f[i+1][j+1][s] = (f[i][j+1][newS]+f[i+1][j][newS])%mod
			}
		}
	}
	return f[m][n][0]
}
