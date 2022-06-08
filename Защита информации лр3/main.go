package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"time"
)

func main() {

	start_time := time.Now()

	alphavit := make(map[byte]int)
	alphavit = Read_alphavit()

	gamma := make([]int, 0)
	gamma = append(gamma, Read_gamma(alphavit)...)

	f, err := os.Create("shifr.txt")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	Read_text(alphavit, gamma)

	end_time := time.Since(start_time)

	fmt.Println(end_time)

	//fmt.Println(alphavit)
	//fmt.Println(gamma)

	//Write_s_text(alphavit)

}

func Rus(sym1 byte, sym2 byte) string {
	sym := []byte{sym1, sym2}
	s := string(sym)
	return s
}

func Sym(sym byte) bool {
	if sym > 127 {
		return true
	}
	return false
}

func Read_alphavit() map[byte]int {

	alphavit := make(map[byte]int)
	text := make([]byte, 1)
	i := 0

	f, err := os.Open("1.txt")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	for {
		_, err := f.Read(text)
		if err == io.EOF {
			break
		}
		alphavit[text[0]] = i
		i++
	}
	return alphavit
}

func Read_gamma(alphavit map[byte]int) []int {
	fname := "2.txt"

	gamma_text, err := ioutil.ReadFile(fname)
	if err != nil {
		fmt.Println(err)
		panic(err)
	}

	gamma := make([]int, 0)
	for i := 0; i < len(gamma_text); i++ {
		gamma = append(gamma, alphavit[gamma_text[i]])
	}
	return gamma

}

func Read_text(alphavit map[byte]int, gamma []int) {
	text := make([]byte, 1024*1024*8)
	//fname := "C:/Users/a8720/source/repos/ConsoleApplication6/ConsoleApplication6/3.txt"
	fname := "text.txt"
	q := 0
	f, err := os.Open(fname)
	if err != nil {
		panic(err)
	}
	defer f.Close()

	for {
		n, err := f.Read(text)
		if err == io.EOF {
			break
		}
		//fmt.Println(text[:n])
		Write_sh_text(Encod_text(alphavit, gamma, text[:n], q))
	}

}

func Encod_text(alphavit map[byte]int, gamma []int, text []byte, q int) []byte {
	encod_text := make([]byte, len(text))
	for i := range text {
		_, ok := alphavit[text[i]]
		if !ok {
			encod_text[i] = text[i]
		} else {
			encod_text[i] = Get_val(alphavit, (alphavit[text[i]]+gamma[q%len(gamma)])%(len(alphavit)))
		}
		q++
		if q == len(gamma) {
			q = 0
		}
	}
	return encod_text
}
func Get_val(alphavit map[byte]int, key int) byte {

	for value, key_ := range alphavit {
		if key == key_ {
			return value
		}
	}
	return 0
}

func Write_sh_text(text []byte) {
	fname := "shifr.txt"

	f, err := os.OpenFile(fname, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0777)
	if err != nil {
		panic(err)
	}
	defer f.Close()

	f.Write(text)
}
