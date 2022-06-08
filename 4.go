package main

import (
	"fmt"
)

func main() {
	var amount, size, a1, a2 int
	var word1, word2 string

	fmt.Scan(&amount)
	if amount > 100 || amount < 1 {
		fmt.Println("Error 1")
	} else {
		for i := 0; i < amount; i++ {
			for {
				fmt.Scan(&size)
				if size > 100 || size < 1 {
					fmt.Println("Error 2")
				} else {
					break
				}
			}

			for {
				fmt.Scan(&word1)
				if len(word1) != size {
					fmt.Println("Error 3")
				} else {
					break
				}
			}

			for {
				fmt.Scan(&word2)
				if len(word2) != size {
					fmt.Println("Error 4")
				} else {
					break
				}
			}

			a1 = 0
			a2 = 0
			for j := range word1 {
				a1 += int(word1[j])
				a2 += int(word2[j])
			}
			if a1 < a2 {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		}
	}

}
