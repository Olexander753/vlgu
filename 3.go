package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	amount := 1
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	fmt.Println(text)

	for i := 0; i < len(text); i++ {
		if string(text[i]) == " " {
			amount++
		}
	}
	fmt.Printf("Квадрат со стороной %v\n", amount)

	for i := 0; i < amount; i++ {
		fmt.Print(text)
	}

}
