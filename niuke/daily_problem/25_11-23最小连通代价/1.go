package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a,b int)int{
	if a<b{
		return a
	}
	return b
}

func solve(n,a,b int,A[]int) int {
	odd,even := 0,0	
	for i:=0;i<n;i++{
		if A[i]%2 == 0{
			even++
		}else{
			odd++
		}
	}

	if odd ==0 || even == 0{
		return (n-1)*a
	}

	cost1:=(n-2)*a + b

	cost2 := (odd-1)*a+even*b
	cost3 :=(even-1)*a+odd*b

	return min(cost1,min(cost2,cost3))

}


func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscan(reader,&T)

	for t:=0;t<T;t++{
		var n,a,b int
		fmt.Fscan(reader,&n,&a,&b)
		A := make([]int,n)
		for i:= 0;i<n;i++{
			fmt.Fscan(reader,&A[i])
		}
	
		ans :=solve(n,a,b,A)
		fmt.Fprintln(writer,ans)
	}
}


