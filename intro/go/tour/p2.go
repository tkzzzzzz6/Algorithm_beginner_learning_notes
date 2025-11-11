package main

import (
	"math"

	"golang.org/x/tour/pic"
)

func Pic(dx, dy int) [][]uint8 {
	slice := make([][]uint8,dx,dy)
	for i:= range slice{
		slice[i] = make([]uint8,dy)
		for j:= range slice[i]{
			slice[i][j] = uint8(float64(i)*math.Log(float64(j)))
		}
	}
	return slice	
}


func main() {
	pic.Show(Pic)
}
