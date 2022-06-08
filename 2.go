package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	var str string
	for {
		fmt.Scan(&N)
		if N < 0 || N > 10000 {
			fmt.Println("Error 1")
		} else {
			break
		}
	}

	arr := make([]int, 0)
	for i := 0; i < N; i++ {
		fmt.Scan(&str)
		x, _ := strconv.Atoi(str)
		arr = append(arr, x)
	}

	index := Max(arr)
	price := (index + 1) * arr[index]
	amount_sell := index + 1

	for i := amount_sell; i < N; i++ {
		index += Max(arr[i:]) + 1
		price = price + (((index + 1) - amount_sell) * arr[index])
		amount_sell = index
		i = index
	}
	fmt.Println(price)
}

func Max(arr []int) int {
	index := 0
	max := arr[0]
	for i := range arr {
		if arr[i] > max {
			max = arr[i]
			index = i
		}
	}
	return index
}
