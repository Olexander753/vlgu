package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	var s string

	f, err := os.Open("C:/Users/a8720/OneDrive/Рабочий стол/Диплом/123.txt")
	if err != nil {
		fmt.Println(err)
	}
	defer f.Close()

	scaner := bufio.NewScanner(f)

	for scaner.Scan() {
		s = scaner.Text()
		s_ := "0"
		if s[57] != byte(s_[0]) {
			s += "\n"
			f_, err := os.OpenFile("big2.txt", os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0777)
			if err != nil {
				panic(err)
			}
			defer f_.Close()

			f_.Write([]byte(s))
		}
	}
}
