package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	fname := "C:/Users/a8720/OneDrive/Рабочий стол/Диплом/123.txt"
	f, err := os.Open(fname)
	if err != nil {
		fmt.Println("Error 1")
	}
	defer f.Close()

	//sym1 := "/n"
	//sym2 := " "
	//sym1_ := rune(sym1[0])

	text := make([]byte, 1024*1024*8)

	for {
		n, err := f.Read(text)
		if err == io.EOF {
			break
		}
		str := string(text[:n])
		rune_arr := []rune(str)
		for i, val := range rune_arr {
			if val == rune(13) {
				rune_arr[i] = rune(10)
			}
		}
		str = string(rune_arr)
		write_([]byte(str))
	}
}

func write_(text []byte) {
	fname := "C:/Users/a8720/OneDrive/Рабочий стол/Диплом/123_.txt"

	f, err := os.OpenFile(fname, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0777)
	if err != nil {
		panic(err)
	}
	defer f.Close()

	f.Write(text)
}
