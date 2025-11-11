package main

import (
	"fmt"
	"math"
)

func Sqrt(x float64) float64 {
	z:= 1.0
	for{
		if math.Abs(z*z-x)<1e-5{
			fmt.Printf("z: %v\n", z)
			return z
		}
		fmt.Printf("z: %v\n", z)
		z -= (z*z-x)/(2*z)
	}
}

func main() {
	fmt.Println(Sqrt(2))
}
