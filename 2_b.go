package main

import "fmt"

func main() {
	var R, r int
	var n int
	for {
		fmt.Scan(&R)
		if R <= 100 || R >= 1 {
			break
		}
	}
	//k := 0
	for i := 0; i < R; i++ {
		fmt.Scan(&n, &r)
		for j := 2; j > 0; j++ {
			if n/i <= r {
				fmt.Println(uint(i - 1))
				break
			}
		}
	}
}
