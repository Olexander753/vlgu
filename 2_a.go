package main

import "fmt"

func main() {
	var M, n, t, f int32
	for {
		fmt.Scan(&M)
		if M < 1000 || M >= 1 {
			break
		}
	}
	M++
	f = 0
	for i := 0; int32(i) < M; i++ {
		fmt.Scan(&n, &t)
		f = factorial(n)
		fmt.Println(f % t)
	}

}

func factorial(n int32) int32 {

	if n == 0 {
		return 1
	}
	return n * factorial(n-1)
}
